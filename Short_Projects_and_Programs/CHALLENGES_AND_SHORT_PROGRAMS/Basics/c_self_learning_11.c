 /***********************************************
	Self Learning C - Basic 11

 This program is the extention of previous demonstration
 and it will have two players to play rock-paper-scissors. 
 Ths program will also announce the winner and ask players 
 if they want to play the game again.
***********************************************/

#include <stdio.h>

void thePRSGame(void);
void clear_keyboard_buffer(void);
enum Choice {ROCK, PAPER, SCISSORS};
typedef enum Choice Choice;
Choice playerInput(void);
void winnerMaker(enum Choice p1, enum Choice p2);
void continuePRS(void);


int main(int argc, char const *argv[])
{
	printf("Welcome to Paper Rock Scissors\n");
	thePRSGame();	
	printf("Good Bye!\n");
	return 0;
}



void thePRSGame(void){
	printf("Player-1 it is your turn!\n");
	enum Choice p1;
	p1 = playerInput();
	printf("Player-2 it is your turn!\n");
	enum Choice p2;
	p2 = playerInput();
	winnerMaker(p1, p2);
	continuePRS();
	return;
}


void continuePRS(void){
	char yesOrNo;
	printf("\nDo you wish to continue? (y/n): ");
	scanf(" %c", &yesOrNo);
	clear_keyboard_buffer();
		if (yesOrNo == 'y' || yesOrNo == 'Y'){
			thePRSGame();
		}
		else if (yesOrNo == 'n' || yesOrNo == 'N'){
			printf("Thank you for playing.\n");
			return;
		}
		else {
			printf("I\'m sorry, I do not understand.");
			continuePRS();
		}
}

Choice playerInput(void){
	printf("Please enter (p)aper, (r)ock, or (s)cissors:");
		char p1;
		scanf(" %c", &p1);

		clear_keyboard_buffer();
			switch(p1) {

				case 'P':
				case 'p':
					return PAPER;

				case 'S':
				case 's':
					return SCISSORS;


				case 'R':
				case 'r':
					return ROCK;

				default:
					printf("I'm sorry but you must enter \'r\', \'p\' or \'s\'.\n");
					playerInput();
			}
	return 0;
}


void winnerMaker(enum Choice p1, enum Choice p2){
	switch(p1) {

		case PAPER:
			if (p2 == ROCK) {
				printf("Paper covers rock. Player 1 Wins!");
			}
			else if (p2 == PAPER) {
				printf("Draw, nobody wins");
			}
			else if (p2 == SCISSORS) {
				printf("Scissors cut paper. Player 2 Wins!");
			}
			break;

		case SCISSORS:
			if (p2 == ROCK) {
				printf("Rock breaks scissors. Player 2 wins!");
			}
			else if (p2 == PAPER) {
				printf("Scissors cut paper. Player 1 wins!");
			}
			else if (p2 == SCISSORS) {
				printf("Draw, nobody wins");
			}
			break;


		case ROCK:
			if (p2 == ROCK) {
				printf("Draw, nobody wins");
			}
			else if (p2 == PAPER) {
				printf("Paper covers rock. Player 2 wins!");
			}
			else if (p2 == SCISSORS) {
				printf("Rock breaks scissors. Player 1 wins!");
			}
			break;
		}
	return;
}



void clear_keyboard_buffer(void){
	char c;
	do{
		scanf("%c", &c);
	}while(c != '\n');
	return;
}