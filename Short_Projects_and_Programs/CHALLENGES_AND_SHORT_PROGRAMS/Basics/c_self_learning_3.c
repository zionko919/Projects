// Self Learning C - Basic 3
// It prints 3 smiley faces. 


#include <stdio.h>

void smile(void);

int main(int argc, char* argv[])
{
	smile(); printf("\n");
	smile(); printf("\n");;
	smile();
	return 0;
}

void smile(void)
{
	printf("  ****\n" );
	printf(" * . .*\n" );
	printf("*      *\n" );
	printf("*  \\_/ *\n" );
	printf(" *    *\n" );
	printf("  ****\n" );
}

