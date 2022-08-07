/***********************************************
	Self Learning C - Basic 8

	This program will prompt the user to 
	enter a negative integer and it will print a 
	message according to the user's input. The user
	must enter a negative number or the program will 
	ask the user to try again.

***********************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int number;
	int continue_loop = 1;
	printf("Please enter a negative integer: ");

	while (continue_loop) 
	{
		scanf("%d", &number);
		if (number < 0) 
		{
			printf("The negative integer was %d\n", number);
			continue_loop = 0;	// stops loop by making it false
		}

		else {
			printf("I\'m sorry, you must enter a negative integer less than 0: ");
		}
		clear_keyboard_buffer();
	}
	return 0;
}

void clear_keyboard_buffer(void){
	char c;
	do
	{
		scanf("%c", &c);
	}while(c != '\n');
	return;
}