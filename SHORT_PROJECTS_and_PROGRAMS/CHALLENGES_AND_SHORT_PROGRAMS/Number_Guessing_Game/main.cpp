/**************************************************
 Purpose: <To get familiar with basics of C++ >

 A text game for guessing random number.
 **************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// All function descriptions are on the bottom.
void getInput(int &number);
void getCharInput(char &yesOrno);
void clearBuffer();
void failCheck();
int askReplayGame();

int main(int argc, char* const argv[]) {
    int min_num = 1, max_num = 1, num_guesses_allowed = 1, random_number, user_guess;
    int playGame = 1, error_min = 1, error_max = 1, error_guessAllowed = 1;

    srand(static_cast<unsigned >(time(NULL)));  // to create a random number

    cout << "********* Welcome to the Game! *********" << endl;

    // While playGame is true, the game will keep going.
    while (playGame) {
        cout << "First, let's set up the game." << endl;

        /* if there is an error with minimum number the user inputs, it will keep asking for the correct value. If
        there is no error then it will break out from the while loop */
        while (error_min) {
            cout << "   Please enter the minimum number, a positive integer: ";
            getInput(min_num);
            failCheck();
            if (min_num < 1 || min_num > 999) {
                cout << "   **Error! Enter a positive number between 1 and 999." << endl;
            } else if (min_num >= 1 && min_num <= 999) {
                break;
            } else {
            }
        }
        /* if there is an error with maximum number the user inputs, it will keep asking for the correct value. If
        there is no error then it will break out from the while loop */
        while (error_max) {
            cout << "   Please enter the maximum number, which is greater than the minimum and less than 1000: ";
            getInput(max_num);
            failCheck();
            // fixed the maximum number to be less than 1000
            if (max_num <= min_num || max_num > 999) {
                cout << "   **Error! Enter a positive number between " << min_num + 1 << " and 999." << endl;
            } else if (max_num > min_num && min_num <= 999) {
                break;
            } else {
            }
        }

        // This will generate a random number between the minimum and the maximum.
        random_number = (min_num) + rand() % (max_num - min_num + 1);

        /* If there is an error with the number the user inputs, it will keep asking for the correct value. If
        there is no error then it will break out from the while loop */
        while (error_guessAllowed) {
            cout << "   Please enter the number of guesses allowed (less than 10): ";
            getInput(num_guesses_allowed);
            failCheck();
            // fixed the number of guesses the user can have to be less than 10.
            if (num_guesses_allowed < 1 || num_guesses_allowed > 9) {
                cout << "   **Error! Enter a positive number between 1 to 9." << endl;
            } else if (min_num >= 1 && min_num <= 10) {
                break;
            } else {
            }
        }

        /* Now the user can input their guesses. These codes will check to see if the user's guesses are matching
          with the random number generated from above. If numbers do not match, it will ask the user to try again
          until there is no tries left and show the number of tries left. If numbers match, it will output a message.
          Also, these codes will check for any errors in the user's input. */
        cout << "Now, I have a number between " << min_num << " and " << max_num << ". Can you guess my number?" << endl;
        cout << "Please type your first guess: ";
        getInput(user_guess);
        failCheck();
        for (int i = 1; i <= num_guesses_allowed; i++) {
            // checks to see if the user's guess is in between the min and max
            if (user_guess > max_num || user_guess < min_num) {
                if (i == num_guesses_allowed) {
                    cout << "You have " << num_guesses_allowed - i << " tries left." << endl;
                    cout << "Sorry, you can't guess any more. The number is " << random_number << endl;
                } else {
                    cout << "You have " << num_guesses_allowed - i << " tries left." << endl;
                    cout << "You have to guess a number between " << min_num << " and " << max_num << "." << endl;
                    cout << "Try again: ";
                    getInput(user_guess);
                    failCheck();
                }
            }
            // checks to see if the user's guess is higher than the random number.
            else if (user_guess > random_number) {
                if (i == num_guesses_allowed) {
                    cout << "You have " << num_guesses_allowed - i << " tries left." << endl;
                    cout << "Sorry, you can't guess any more. The number is " << random_number << endl;
                } else {
                    cout << "You have " << num_guesses_allowed - i << " tries left." << endl;
                    cout << "Too high! Try again: ";
                    getInput(user_guess);
                    failCheck();
                }
            }
            // checks to see if the user's guess is lower than the random number.
            else if (user_guess < random_number) {
                if (i == num_guesses_allowed) {
                    cout << "You have " << num_guesses_allowed - i << " tries left." << endl;
                    cout << "Sorry, you can't guess any more. The number is " << random_number << endl;
                } else {
                    cout << "You have " << num_guesses_allowed - i << " tries left." << endl;
                    cout << "Too low! Try again: ";
                    getInput(user_guess);
                    failCheck();
                }
            }
            // checks to see the user's guess match with the random number.
            else if (user_guess == random_number) {
                cout << "Excellent! You guessed the number!" << endl;
                break;
            } else {
            }
        }
        // if askReplayGame comes out to be 1, then the game replays. if it comes out to be 0, then the game stops.
        playGame = askReplayGame();
    }
        return 0;
}

// a void function that gets an integer value from the user and pass it by reference.
void getInput(int &number)
{
    cin >> number;
}

// a void function that gets a character value from the user and pass it by reference.
// I did not use the function overload since I just need it once.
void getCharInput(char &yesOrno)
{
    cin >> yesOrno;
}

/* a void function that takes in nothing and checks to see if the command fails when using cin. For example,
 if the user tries to input a character value into an integer variable, this function will check to see if it fails.
 If it does fail, then the computer will output an error message. */
void failCheck()
{
    if (cin.fail()) {
        cout << "   **Error! Please only enter a positive integer." << endl;
        clearBuffer();
    }
}

/* This function will ask the user whether or not he/she wants to play the game again. This function will return an
  integer value of either 0 or 1. If it returns 0 the game will break out from the while loop in the main function
  and quits the game. If it returns 1 then the while loop will start from the very top. */
int askReplayGame() {
    int error_replay = 1;
    char yesOrno;
    while (error_replay) {
        cout << "Would you like to play the game again? (y/n): ";
        getCharInput(yesOrno);
        yesOrno = tolower(yesOrno);
        if (yesOrno == 'y') {
            error_replay = 1;
            return error_replay;
        } else if (yesOrno == 'n') {
            error_replay = 0;
            cout << "Good Bye!" << endl;
            return error_replay;
        } else {
            cout << "**Error! I could not recognize your input. Please enter y or n." << endl;
        }
    }
    return -777;    // I just use -777 to identify errors in the function if they happen.
}

// It is just a good old keyboard buffer function that returns void and takes in nothing.
void clearBuffer()
{
    cin.clear();
    cin.ignore(10000000, '\n');
}