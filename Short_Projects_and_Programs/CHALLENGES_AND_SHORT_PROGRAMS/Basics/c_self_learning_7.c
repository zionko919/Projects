 /***********************************************
	Self Learning C - Basic 7
	Recursions
 ***********************************************/

#include <stdio.h>

// forward function declarations 
void loop_down_to_zero(int num);
void loop_up_to_int(int num);


int main(int argc, char* argv[])
{
	int num;
	printf("Please enter a positive number: ");
	scanf("%d", &num);
	loop_down_to_zero(num);
	printf("****\n");
	loop_up_to_int(num);

	return 0;
}

void loop_down_to_zero(int num)
{
	while(num >= 0)
	{
		printf("%d\n", num);
		num -= 1;
	}
}

void loop_up_to_int(int num)
{
	int start = 0;
	while(num >= start)
	{
		printf("%d\n", start);
		start += 1;
	}
}

