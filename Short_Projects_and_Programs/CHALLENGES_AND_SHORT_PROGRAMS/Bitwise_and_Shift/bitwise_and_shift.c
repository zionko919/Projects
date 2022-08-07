/***********************************************************
Purpose: <To practice and use bitwise operators and shifts
 creatively>
************************************************************/

#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);


int main(int argc, char* argv[])
{

    unsigned int flag_holder = 0;

    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);

    display_32_flags(flag_holder);

    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);

    display_32_flags(flag_holder);

    return 0;
}


void set_flag(unsigned int* flag_holder, int flag_position)
{
    int temp_1 = 0;
    temp_1 = (1|temp_1);     // 1 or 0, this would always give out 1.
    temp_1 = temp_1<<flag_position;  // left shifts by the value of the flag_position
    *flag_holder = temp_1|*flag_holder;  /* temp_1(left shifted value) or flag_holder(0)
                                        this would store temp_1 value into *flag_holder */
}

int check_flag(unsigned int flag_holder, int flag_position)
{
    int temp_2;
    flag_holder = flag_holder >> flag_position;  // right shifts flag_holder by the value of flag_postion
    if(flag_holder%2==0) {
        temp_2 = 0;
    }
    else temp_2 = 1;     // if-else is checking to flag_holder value is 0 or 1
    return temp_2;
}

void unset_flag(unsigned int* flag_holder, int flag_position)
{
    unsigned int temp_a = 0;
    unsigned int temp_b = *flag_holder;
    
    temp_b = ~temp_b;   // flips temp_b bits
    temp_a = (1|temp_a);    // bitwise OR to flip 0 to 1
    temp_a = temp_a<<flag_position;
    temp_b = temp_b|temp_a;
    *flag_holder = ~temp_b;
}

void display_32_flags(unsigned int flag_holder)
{
    int i;
    for(i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}
