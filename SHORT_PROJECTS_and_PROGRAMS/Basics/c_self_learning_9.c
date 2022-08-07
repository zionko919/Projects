 /***********************************************
 	Self Learning C - Basic 9

	This program will print out asterisks 
	according to the user's input. If the user's input
	is out of range, it will askk the user to put a 
	new number between [1-79]
***********************************************/

#include <stdio.h>

int numberRange(void);
void drawAsterisks(int num);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int num_asterisk;
	num_asterisk = numberRange();
	drawAsterisks(num_asterisk);
	printf("\n");
	return 0;
}

int numberRange(void)
{
	int number;
	printf("Please enter the number of asterisks you want in your line: ");
	while(1){
		scanf("%d", &number);
		if(number >= 1 && number <= 79){	
			break;
		}
		else{
			printf("I\'m sorry, that number is unrecongnized or out of range, try [1-79]: ");
		}
		clear_keyboard_buffer();
	}
	return number;
}

void drawAsterisks(int num)
{
	int i = 0;
	while (i < num){
		printf("*");
		i += 1;
	}
	return;
}


void clear_keyboard_buffer(void)
{
	char c;
	do
	{
		scanf("%c", &c);
	}while(c != '\n');
	return;
}