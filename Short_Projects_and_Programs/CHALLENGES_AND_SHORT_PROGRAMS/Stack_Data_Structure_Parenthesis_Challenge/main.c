/***********************************************
Purpose: To learn about stack in C and us stack
 data structures to solve problems.
***********************************************/

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "my_stack.h"


int main()
{
    STACK hStack;
    int nums_strings;
    int i;
    char temp[CHAR_MAX];

    scanf("%d", &nums_strings);
    clear_keyboard_buffer();
    for (i = 1; i <= nums_strings; i++) {
        hStack = stack_init_default();
        scanf("%[^\n]", temp);
        stack_char_checker(hStack, temp);
//        clear_keyboard_buffer();
        while (getchar() != '\n');
        memset(temp, 0, sizeof(temp));
        stack_destroy(&hStack);
    }

    return 0;
}