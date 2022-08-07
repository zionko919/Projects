/***********************************************************
    <To practice and use bitwise operators and shifts
 creatively>
************************************************************/

#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);
int check_flag(unsigned int flag_holder[], int flag_position);


int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = {0};

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);


    display_flags(flag_holder, 5);
    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);


    display_flags(flag_holder, 5);


    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    int num_bits = (sizeof(int)*8);
    int arr_num = flag_position / num_bits;
    int arr_position = flag_position % num_bits;
    int flag = 1;
    flag <<= arr_position;
    flag_holder[arr_num] = flag|flag_holder[arr_num];

}


void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int num_bits = (sizeof(int)*8);
    int arr_num = flag_position / num_bits;
    int arr_position = flag_position % num_bits;
    int flag = 1;
    flag <<= arr_position;
    flag_holder[arr_num] = flag &~ flag_holder[arr_num];
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    int temp = *flag_holder;
    temp >>= flag_position;

    if(temp % 2 == 0){
        return 0;
    } else {
        return 1;
    }
}

void display_32_flags_as_array(unsigned int flag_holder)
{
    int num_bits = (sizeof(int)*8);
    for(int i = 0; i < num_bits; i++)
    {
        if(i % 4 == 0){
            printf(" ");
        }
        printf("%d", check_flag(&flag_holder, i));
    }
    printf("\n");
}

void display_flags(unsigned int flag_holder[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        display_32_flags_as_array(flag_holder[i]);
    }
}