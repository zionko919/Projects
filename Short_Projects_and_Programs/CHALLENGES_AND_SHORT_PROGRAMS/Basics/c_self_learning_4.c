/***********************************************
Self Learning C - Basic 4
*************************************************/

/* This program will count down to 0 from USER's 
input and count back up to USER's input from 0 */

#include <stdio.h>


void recursiveDownToZero(int num);
void recursiveUpToInt(int num);

int main(int argc, char* argv[])
{
	int number;

	printf("Please enter a positive integer: ");
	scanf("%d" , &number);
	recursiveDownToZero(number);
	printf("****\n");
	recursiveUpToInt(number);


	return 0;
}

void recursiveDownToZero(int num) {

	if (num >= 0) {
		printf("%d\n", num);
		recursiveDownToZero(num-1);
	}
	return;
}

void recursiveUpToInt(int num) {

	if (num >= 0 ) {
		recursiveUpToInt(num-1);
		printf("%d\n", num);
	}
	return;
}

