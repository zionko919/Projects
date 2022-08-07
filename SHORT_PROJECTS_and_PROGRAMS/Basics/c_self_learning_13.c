/***********************************************
Self Learning C - Basic 13

This program converts values that are
length or weights. This is a refinement version
of previous demonstration.
***********************************************/

#include <stdio.h>

void conversion(void); // Asks the user to select between weights and lengths.
void convert_weights(void);
void convert_lengths(void);
void clear_keyboard_buffer(void);
void length_to_metric(void);
void length_to_us(void);
void weight_to_metric(void);
void weight_to_us(void);

int main (int agrc, char const *argv[])
{
    printf("Welcome, I am a conversion program.\n");
    conversion();
    return 0;
}


void conversion(void)
{
    int choice = 1;
    while (choice != 0) {
        printf("MAIN MENU: Select (1) to convert lengths, (2) to convert weights, (0) to terminate the program: ");
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
    int user_unit = 1;        
    printf("***You are converting lengths.***\n");
    while(user_unit != 0) {
        printf("Select (1) feet/inches to meters/centimeters, (2) meters/centimeters to feet/inches, or (0) to go back: " );
        scanf("%d", &user_unit);
        clear_keyboard_buffer();

        switch (user_unit)
        {
            case 1: length_to_metric();
                break;

            case 2: length_to_us();
                break;

            case 0: 
                break;

            default: printf("I do not understand. Please follow the instruction.\n");
                break;
        }
    }
    return;
}

void length_to_metric(void)
{
    printf("***You have selected US to METRIC conversion in lengths.***\n");
    return;
}

void length_to_us(void)
{
    printf("***You have selected METRIC to US conversion in lengths.***\n");
    return;
}

void convert_weights(void)
{
    int user_unit = 1;
    printf("***You are converting weights.***\n");
    while(user_unit != 0) {
    printf("Select (1) pounds/ounces to kilograms/grams, (2) kilograms/grams to pounds/ounces, or (0) to go back: " );
    scanf("%d", &user_unit);
    clear_keyboard_buffer();
  
        switch (user_unit)
        {
            case 1: weight_to_metric();
                break;

            case 2: weight_to_us();
                break;

            case 0: 
                break;

            default: printf("I do not understand. Please follow the instruction.\n");
                break;
        }
    }
    return;
}

void weight_to_metric(void)
{
    printf("***You have selected US to METRIC conversion in weights.***\n");
    return;
}

void weight_to_us(void)
{
    printf("***You have selected METRIC to US conversion in weights.***\n");
    return;
}

void clear_keyboard_buffer(void){
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');
    return;
}