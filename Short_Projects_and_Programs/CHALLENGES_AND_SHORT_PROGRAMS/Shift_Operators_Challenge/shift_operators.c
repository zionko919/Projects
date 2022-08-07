/***********************************************************
Purpose: <to learn left and right shift operators, 
            and the unsigned int>
***********************************************************/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    unsigned int b=1;

    for (a=0; b!=0; a++){
        printf("%d: %u\n", a, b);
        b = b << 1;
    }

    return 0;
}