/*********************************************************
 A number guessing gmae.
 It utilizes objected-oriented fashion.
 Polymorphism...
 ********************************************************/


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
public:
    virtual int getGuess(void) = 0;
//    {
//        return 0;
//    }
    int answerResult;
    int opponentsGuess;
};

class HumanPlayer : public Player {
public:
    int getGuess(void) override;
    void clearBuffer() {
        cin.clear();
        cin.ignore(10000, '\n');
    }
    int human_num;
};

int HumanPlayer::getGuess() {
    int num, error = 1;
    while (error) {
        cin >> num;
        // if the player puts anything other than integer... error message will pop up
        if (cin.fail()) {
            clearBuffer();
        }
        // error message - if the player puts anything less than 1 or anything over 100
        if (num < 1 || num > 100) {
            cout << "**Error! Enter a number between 1 and 100: ";
        } else if (num >= 1 && num <= 100) {
            break;
        }
    }
    return num;
}

class ComputerPlayer : public Player {
public:
    int getGuess(void) override;
    int firstGuess(void) {
        int firstGuess = (rand() % 100) + 1;
        return firstGuess;
    };
private:
    int myGuess;
    int highest = 101;
    int lowest = 0;
    int count = 0;
};

int ComputerPlayer::getGuess() {
    int comGuess;
    count += 1;
    if (count == 1 && opponentsGuess == 0) {
        comGuess = firstGuess();
        myGuess = comGuess;
    } else if (count >= 1 && opponentsGuess != 0) {
        // Higher than the answer
        if (opponentsGuess > answerResult) {    // if other player's guess is highter than the answer
            if (opponentsGuess > highest) {     // This if statement may not be needed
                highest = highest;
            } else if (opponentsGuess < highest) { // if other player's guess lower than current highest
                highest = opponentsGuess - 1;   // then highest is one less than other's guess
            }
            comGuess = lowest + (rand() % (highest - lowest + 1));  // random guess
            myGuess = comGuess;
            if (myGuess < answerResult) {   // if my guess is less than the answer
                lowest = myGuess + 1;
            } else if (myGuess > answerResult) { // if my guess is higher than the answer
                highest = myGuess - 1;
            }
        }
        // Lower than the answer
        else if (opponentsGuess < answerResult) {   // Pretty much as same as 'high', but everything is flipped
            if (opponentsGuess < lowest) {
                lowest = lowest;
            } else if ( opponentsGuess > lowest) {
                lowest = opponentsGuess + 1;
            }
            comGuess = lowest + (rand() % (highest - lowest + 1));
            myGuess = comGuess;
            if (myGuess > answerResult) {
                highest = myGuess - 1;
            } else if (myGuess < answerResult) {
                lowest = myGuess + 1;
            }
        }
    }
    cout << "The computer guesses " << comGuess << endl;
    if (comGuess > 100 || comGuess < 1) {   // This error message will never reach if everything works correctly
        cout << "Fatal Error!"<< endl;
        exit(1);
    }
    return comGuess;
}

bool checkForWin(int guess, int answer);
void play(Player &player1, Player &player2);

int main(int argc, char * const argv[])
{
    srand(static_cast<unsigned >(time(NULL)));  // to create a random number

    ComputerPlayer com1, com2;
    HumanPlayer me;

    // human vs computer
    play(me, com2);

    // computer vs human
//    play(com1, me);

    // computer vs computer
//    play(com1, com2);

    return 0;
}

// Given from the textbook
bool checkForWin(int guess, int answer) {
    if (answer == guess)
    {
        cout << "   You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess) {
        cout << "   Your guess is too high." << endl;
    }
    else {
        cout << "   Your guess is too low." << endl;
    }
    return false;

}

// The play function takes as input two Player objects.
void play(Player &player1, Player &player2) {
    int answer = 0, guess = 0;
    answer = rand() % 100;
//    answer = 50;
    bool win = false;
    player1.answerResult = answer;
    player2.answerResult = answer;
//    cout << "Answer: " << answer << endl;
    while (!win) {
        cout << "Player 1's turn to guess: ";
        guess = player1.getGuess();
        player2.opponentsGuess = guess;
        win = checkForWin(guess, answer);
        if (win) return;
        cout << "Player 2's turn to guess: ";
        guess = player2.getGuess();
        player1.opponentsGuess = guess;
        win = checkForWin(guess, answer);
    }
}