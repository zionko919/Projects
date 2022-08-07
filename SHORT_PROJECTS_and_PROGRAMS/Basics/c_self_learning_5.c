/***********************************************
Self Learning C - Basic 5

This program will use reursion to output
the binary representation of any postive integer.
The purpose is learning how to program using 
the recursion method and using arithmetic 
operators. Also, it demonstartes the binary number
conversion. 
*************************************************/

#include <stdio.h>

void print_binary(int num)
{
	if(num > 0)
	{
		print_binary(num / 2);
		printf("%d", num % 2);
		return;
	}
	else if(num < 0)
	{
		printf("Please enter a positive integer.");
	}
}

int main(int argc, char* argv[])
{
	int num;
	printf("\"Binary Converter\" - Enter a postive integer you wish to convert: ");
	scanf("%d", &num);
	print_binary(num);
	printf("\n");
	return 0;
}