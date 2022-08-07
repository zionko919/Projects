/* Self Learning C - Basic 18 */

#include <stdio.h>

// FORWARD DECLARATIONS
int digitSum(int number);


int main(int argc, char * argv[])
{
    int     num;
    int     sum;

    // Prompt for, and receive user input
    printf("Enter a number whose digits should be summed: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Sorry, you didn't enter a number.\n");
        return 1;
    }
    
    // Calculate the sum of the digits of the provided number
    sum = digitSum(num);
    
    // Print out the result.
    printf("The sum of the digits of %d is %d\n", num, sum);
    
    // Return success
    return 0;
}


/**
 * Calculate and return the sum of the digits of a given number.
 * 
 * @param number
 *   The number whose digits are to be summed
 * 
 * @return
 *   The sum of the number's digits
 */
int digitSum(int number)
{
    int     digit;
    int     sumOfDigits = 0;
    
    while (number != 0)
    {
        // Get the next digit
        digit = number % 10; // just needed to change it to modulo
        
        // Add this digit to the sum
        sumOfDigits = sumOfDigits + digit;
        
        // Prepare for next digit
        number = number / 10;
    }
    
    // Give 'em the sum
    return sumOfDigits;
}
