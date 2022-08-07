 /***********************************************
	Self Learning C - Basic 6
 	scanf() and 'if' statements
 ***********************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
	int num;

	printf("Please enter a positive number: ");
	scanf("%d", &num);

	if (num % 2 == 0)
	{
		num = num / 2;
		printf("The next value of the number is: %d\n", num);
	}
	else
	{
		num = num * 3 + 1;
		printf("The next value of the number is: %d\n", num);
	}

	return 0;
}