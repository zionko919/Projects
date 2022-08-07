/***********************************************
    Self Learning C - Basic 21
 ***********************************************/

#include <stdio.h>
#include <learncs.h>
#include <stdlib.h>

// FORWARD DECLARATIONS
void exercise2(void);
void exercise3(void);
void exercise4(void);
int stringLength(char arr[]);
int countSpaces(char arr[]);
void removeVowels(char arr[]);


// main()
// Do not change this function at all.
int main(int argc, char * argv[])
{
    exercise2();
    exercise3();
    exercise4();
    printf("\n");
    return 0;
}


void exercise2(void)
{
    char    arr[16];    
    int     magic = 42;

    printf("\n--------------------\n");
    printf("EXERCISE 2\n");
    printf("--------------------\n\n");

    // Print out the magic value
    printf("magic = %d\n", magic);
    
    // Prompt for string input
    printf("Enter a character string: ");
    
    // Retrieve up to 16 characters (plus the null terminator)
    getString(arr, 16); // delete +1 to make it work with arr[16]
    printf("The length of string [%s] is %d\n", arr, stringLength(arr));
    
    // Print out the magic value again
    printf("magic = %d\n", magic);

    /*
        Provide the Exercise 2a explanation here, in this comment:
        When the user types in more than 16 characters, the magic number changes to 0. 
        It is because, the arr[16] only can hold a maximum number of 15 characters. 
        However, getSrting function is trying to read 16 characters from 
        doing getString(arr, 16+1) and a room for a null, which means that there is no room 
        to terminate the c-string with a null character. 
        To fix it, delete, +1 from the getString so it become getString(arr, 16). 
    */

}


void exercise3(void)
{
    int         spaces;
    char        string[] =
      "This is a test of the emergency broadcasting system. This is only a test.";
    
    printf("\n--------------------\n");
    printf("EXERCISE 3\n");
    printf("--------------------\n\n");
    
    // Count the number of spaces in the string.
    spaces = countSpaces(string);
    
    // The original countSpaces() function you are given simply returns -1.
    // If it still does that, it just means that you haven't yet implemented
    // the countSpaces() function according to the Exercise 2 instructions.
    if (spaces == -1)
    {
        printf("This exercise has not been completed yet.\n");
    }
    else
    {
        printf("The number of spaces in [%s] is %d\n", string, spaces);
    }
}


void exercise4(void)
{
    int         removed;
    char        string[] =
      "This is a test of the emergency broadcasting system. This is only a test.";
    
    printf("\n--------------------\n");
    printf("EXERCISE 4\n");
    printf("--------------------\n\n");
    
    // Count the number of spaces in the string.
    removed = removeVowels(string);
    
    // The original removeVowels() function you are given simply returns -1.
    // If it still does that, it just means that you haven't yet implemented
    // the countSpaces() function according to the Exercise 2 instructions.
    if (removed == -1)
    {
        printf("This exercise has not been completed yet.\n");
    }
    else
    {
        printf("%d vowels were removed, yielding [%s]\n", removed, string);
    }
}


/**
 * Calculate the length of a character string
 * 
 * @param arr
 *   The address of the first element of an array of characters containing
 *   the string.
 * 
 * @return
 *   The number of characters in the string, not including the string's
 *   null terminator.
 */
int stringLength(char arr[])
{
    int     len;
    
    // Assume initially that the array is length 0.
    len = 0;
    
    // Look at each element of the array. If we find something other than
    // the null terminator, count this character by incrementing the length
    // variable.
    while (arr[len] != '\0')
    {
        // This character wasn't the null terminator, so increment the length
        ++len;
    }
    
    // Give 'em the calculated string length
    return len;
}


/**
 * Count the number of space characters in a string.
 * 
 * @param arr
 *   The address of the first element of an array of characters containing
 *   the string.
 * 
 * @return
 *   The number of space characters in the string.
 */
int countSpaces(char arr[])
{
    int i;
    int ctr = 0;
    
    for (i = 0; i < stringLength(arr); ++i){
        if (arr[i] ==' '){
            ctr += 1;
        }
    }
    // When you implement this function, the following return statement
    // will be removed/replaced by your code.
    return ctr;
}


/**
 * "Remove" each vowel from the provided character array, moving all
 * subsequent characters forward in the array to take up the space of the
 * removed vowel. Only the following characters are considered to be vowels:
 * 'a', 'e', 'i', 'o', and 'u'
 * 
 * @param arr
 *   The address of the first element of an array of characters containing
 *   the string whose vowels are to be removed.
 * 
 * @return
 *   The number of vowels removed from the provided string.
 */
int removeVowels(char arr[])
{
    int i, j = 0;
    int ctr = 0;

    for (i = 0; arr[i] != '\0'; i++){
        if ((arr[i] != 'a') && (arr[i] != 'e') && (arr[i] != 'i') && (arr[i] != 'o') && (arr[i] != 'u')
        && (arr[i] != 'A') && (arr[i] != 'E') && (arr[i] != 'I') && (arr[i] != 'O') && (arr[i] != 'U')) {
            arr[j] = arr[i];
            j++;
        }
        else{
            ctr += 1;
        }
    }
    arr[j] = '\0';

    // When you implement this function, the following return statement
    // will be removed/replaced by your code.
    return ctr;
}

