/***********************************************
    Self Learning C - Basic 25

    The purpose of this program is to
    calculate the Green Crud growth using Fibonacci
    number.
***********************************************/


#include <stdio.h>

// forward function declarations
int fibonacci(int size, int cycle);
int initial_size(void);
int num_of_days(void);
int ask_to_continue(void);

// main function
int main(int argc, char const *argv[])
{
    int result;
    int initial_pop;
    int days;
    int growth_days = 5;    // Given, since the crud grows after 5 days.
    int cycle;
    int yesOrNo = 1;

    // while loop to repeat the process if the user chooses YES to continue.
    while(yesOrNo) {
        initial_pop = initial_size();
        days = num_of_days();
        // if the growing day is less than 5 days.
        if (days < 5) {
            printf("With initial population of %d pounds of crud growing for %d days.\n", initial_pop, days);
            printf("The final population would be %d pounds.\n", initial_pop);
            yesOrNo = ask_to_continue(); // if yesOrNo is Zero, the program exits the loop and terminates.
        }
        // if the growing day is more than or equal to 5 days.
        else {
            cycle = days / growth_days;
            /* since the crud grows after a 5 days cycle,
             * you have to divide 5 from number of days to calculate
             * how many times it grows during these days.*/

            result = fibonacci(initial_pop, cycle); // initial population and cycle to determine the final_result
            printf("With initial population of %d pounds of crud growing for %d days.\n", initial_pop, days);
            printf("The final population would be %d pounds.\n", result);
            yesOrNo = ask_to_continue(); // if yesOrNo is Zero, the program exits the loop and terminates.
        }
    }
    return 0;
}

// This function calculates the final result of the crud growing.
int fibonacci(int size, int cycle)
{
    int i;
    int new_size;   // new_size for the final result.
    int f_1 = 0;    // fibonacci 1 starts with 0.
    int f_2 = size; // fibonacci 2 starts with the initial population.

    // for loop to go through the fibonacci sequence. It ends when it reaches the final cycle.
    for(i = 0; i < cycle; i++){
        new_size = f_1 + f_2;   // Fn = Fn-1 + Fn-2 for n > 1 meaning that each number is the sum of previous numbers in the sequences
        f_1 = f_2;  // f_2 becomes f_1
        f_2 = new_size; // f_2 becomes new_size.
    }
    return new_size;
}

int initial_size(void)
{
    int size;
    printf("Please enter the initial size of the green crud: ");
    scanf("%d", &size);
    if (size <  0 ){
        printf("I'm sorry that value is unrecognized or is negative.\n");
        initial_size(); // used recursion to repeat the function.
    }
    else
        return size;
}

int num_of_days(void)
{
    int days;
    printf("Please enter the number of days: ");
    scanf("%d", &days);
    if (days < 0 ){
        printf("I'm sorry that value is unrecognized or is negative.\n");
        num_of_days(); // used recursion to repeat the function.
    }
    else
        return days;
}

/* ask_to_continue function is to give an integer value to be used in the main function
 * to exit out of the while loop to continue the whole process or not. */
int ask_to_continue(void)
{
    char yesOrNo;
    int choice;
    printf("Would you like to continue? (Y/N): ");
    scanf(" %c", &yesOrNo);
    if (yesOrNo == 'y' || yesOrNo == "Y"){
        choice = 1;
    }
    else if(yesOrNo == 'n' || yesOrNo == "N"){
        printf("Good Bye!\n");
        choice = 0;
    }
    else{
        printf("I'm sorry please try again.\n");
        ask_to_continue();
    }
    return choice;
}
