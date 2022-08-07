/***********************************************
    Self Learning C - Basic 24
    
    This program prints out a list of
    numbers given by the user, and shows how many
    steps it takes to get down to 1 using the Collatz
    conjecture method.
***********************************************/

#include <stdio.h>

//forward function declaration
void clear_keyboard_buffer(void);
int calculation(int number, int length);
void collatz(void);


// main function
int main(int argc, char const *argv[])
{
    collatz();
    return 0;
}

// This function lets the user input their starting number and ending number
// Then it uses for loops to call calculation function for numbers starting with the user's starting number to ending number
// The it prints the output.
void collatz(void)
{
    int start, end;
    int i;

    printf("Enter a starting point: ");
    scanf("%d", &start);
    clear_keyboard_buffer();
    printf("Enter an ending point: ");
    scanf("%d", &end);
    clear_keyboard_buffer();

    while (start <= end){
        for (i = 1; i < end; i++){
            int steps = 0;
            steps = calculation(start, steps);
            printf("%5d:%-5d ", start, steps);  // right space 5, left space 5.
            start += 1;
            if(i%7 ==0){
                printf("\n");   // a new line is created after printing out 7 outputs
            }
        }
    }
    return;
}

// This calculation function uses 'if' to see a number is even or odd.
// It recalls calculation function so it can find how many steps to reach down to 1.
int calculation(int number, int length)
{
    int value1 = number;
    int steps = length;
    while (value1 != 1)
    {
        steps++;
        if (value1 % 2 == 0)
            return calculation(value1 / 2, steps);
        else
            return calculation(3 * value1 + 1, steps);
    }
    return steps;
}


void clear_keyboard_buffer(void)
{
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');
    return;
}
