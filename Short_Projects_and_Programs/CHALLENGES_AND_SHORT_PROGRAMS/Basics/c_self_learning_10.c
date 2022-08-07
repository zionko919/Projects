/***********************************************
Self Learning C - Basic 10

This program will have two players to
play rock-paper-scissors. Ths program will also
announce the winner and ask players if they want
to play the game again
***********************************************/

#include <stdio.h>

void PRSgame(void);
char player1(void);
char player2(void);
void winnerMaker(void);
void continuePRS(void);



int main(int argc, char const *argv[] )
{
    PRSgame();
    return 0;
}


void PRSgame(void)
{
    winnerMaker();
    continuePRS();
    return;
}


void continuePRS(void)
{
    char yesOrNo;
    printf("Do you wish to continue? (Y/N): ");
    scanf(" %c", &yesOrNo);
    if (yesOrNo == 'y' || yesOrNo == 'Y'){
        PRSgame();
    }
    else if (yesOrNo == 'n' || yesOrNo == 'N'){
        printf("Thank you for playing.");
        return;
    }
    else {
        printf("I\'m sorry, I do not understand. Enter \'Y\' or \'N\'\n");
        continuePRS();
    }

}

void winnerMaker(void)
{
    char p1 = player1();
    char p2 = player2();
    if (p1 == p2) {
        printf("Draw, nobody wins!\n");
    }
    else if ((p1 == 'r' || p1 == 'R') && (p2 == 's' || p2 == 'S')){
        printf("Rock breaks scissors. Player 1 wins!\n");
    }
    else if ((p2 == 'r' || p2 == 'R') && (p1 == 's' || p1 == 'S')){
        printf("Rock breaks scissors. Player 2 wins!\n");
    }
    else if ((p1 == 'S' || p1 == 's') && (p2 == 'P' || p2 == 'p')){
        printf("Scissors cut paper. Player 1 wins!\n");
    }
    else if ((p2 == 'S' || p2 == 's') && (p1 == 'P' || p1 == 'p')){
        printf("Scissors cut paper. Player 2 wins!\n");
    }
    else if ((p1 == 'P' || p1 == 'p') && (p2 == 'R' || p2 == 'r')){
        printf("Paper covers rock. Player 1 wins!\n");
    }
    else if ((p2 == 'P' || p2 == 'p') && (p1 == 'R' || p1 == 'r')){
        printf("Paper covers rock. Player 2 wins!\n");
    }
    return;
}


char player1(void)
{
    char p1;
    int count = 1;
    printf("Player 1 it is your turn!\n");
    while (count) {
        printf("Please choose (p)aper, (r)ock, or (s)cissors: ");
        scanf(" %c", &p1);
        if (p1 == 'r' || (p1 == 'p' || p1 == 's')) {
            count = 0;
        }
        else if (p1 == 'R' || (p1 == 'P' || p1 == 'S')) {
            count = 0;
        }
        else{
            printf("I\'m sorry but you must enter \'r\', \'p\', or \'s\'\n");
        }
    }
    return p1;
}

char player2(void)
{
    char p2;
    int count = 1;
    printf("Player 2 it is your turn!\n");
    while (count) {
        printf("Please choose (p)aper, (r)ock, or (s)cissors: ");
        scanf(" %c", &p2);
        if (p2 == 'r' || (p2 == 'p' || p2 == 's')) {
            count = 0;
        }
        else if (p2 == 'R' || (p2 == 'P' || p2 == 'S')) {
            count = 0;
        }
        else{
            printf("I\'m sorry but you must enter \'r\', \'p\', or \'s\'\n");
        }
    }
    return p2;
}