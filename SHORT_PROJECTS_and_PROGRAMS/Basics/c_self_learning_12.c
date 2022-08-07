/***********************************************
Self Learning C - Basic 12

This program converts values that are length or weights

***********************************************/

#include <stdio.h>

void conversion(void); // Asks the user to select between weights and lengths.
void convert_weights(void);
void convert_lengths(void);
void clear_keyboard_buffer(void);


int main (int agrc, char const *argv[])
{
    printf("Welcome, I am a conversion program.\n");
    conversion();
    return 0;
}


void conversion(void)
{
    int choice;

    while (choice != 0) {
        printf("Select (1) to convert lengths, (2) to convert weights, (0) to terminate the program: ");
        scanf("%d", &choice);
        clear_keyboard_buffer();
   
        switch  (choice)
        {
            case 1: convert_lengths();
                    break;

            case 2: convert_weights();
                    break;

            case 0: printf("Good Bye!\n");
                    break;

            default: printf("I do not understand. Please follow the instruction.\n");
                    break;
        }
    }
    return;
}

void convert_lengths(void)
{
    printf("You are converting lengths.\n");
    return;
}

void convert_weights(void)
{
    printf("You are converting weights.\n");
    return;
}

void clear_keyboard_buffer(void){
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');
    return;
}