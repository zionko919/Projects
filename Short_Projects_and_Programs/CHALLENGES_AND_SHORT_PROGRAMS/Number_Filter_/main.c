/**********************************************************************
  Purpose: The purpose of this program is to output the list of numbers 
  as a sorted list. However it needs to hold an enormous number of
  input values and remove all duplicates.

  It is a program that will filter a list of non-negative integers 
  such that all duplicate values are removed. Integer values will come 
  from standard input (the keyboard) and will range in value from 0 up 
  to 2,000,000,000. Input will be terminated by the special value, -1.
  Once the input is read in you should output (to the screen) the list 
  of numbers as a sorted list (smallest to largest) with one value 
  listed per line where all duplicates have been removed.
***********************************************************************/

#include <stdlib.h>
#include <stdio.h>

enum status { FAILURE, SUCCESS };
typedef enum status Status;
struct bit_flags {
    int size;
    int capacity;
    int* data;
};

typedef struct bit_flags Bit_flags;
typedef void* BIT_FLAGS;
BIT_FLAGS bit_flags_init_number_of_bits();
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position);
void bit_flags_destroy(BIT_FLAGS* phBit_flags);


int main(int argc, char* argv[]) {
    unsigned int big_num = 2147483648;
    int i, j, num;
    int terminator = -1;
    int count = 0;
    BIT_FLAGS hBit_flags = NULL;
    hBit_flags = bit_flags_init_number_of_bits();
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    scanf("%d", &num);
    while (num != terminator) {

        bit_flags_set_flag(hBit_flags, num);
        scanf("%d", &num);
    }

    for (i = 0; i < pBit_flags->capacity; i++) {
        for (j = 0; j < 32; j++) {
            if (((big_num >> j)&(pBit_flags->data[i])) != 0) {
                printf("%d\n", count);
            }
            count++;
        }

    }
    bit_flags_destroy(&hBit_flags);
    return 0;
}
BIT_FLAGS bit_flags_init_number_of_bits()
{
    int i;
    Bit_flags* pBit_flags;
    pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
    if (pBit_flags != NULL)
    {
        pBit_flags->size = 0;
        pBit_flags->capacity = 1;
        pBit_flags->data = (int*)(malloc(sizeof(int)*(pBit_flags->capacity)));

        if (pBit_flags->data == NULL)
        {
            free(pBit_flags);
            pBit_flags = NULL;
            return pBit_flags;
        }

        for (i = 0; i < pBit_flags->capacity; i++)
        {
            pBit_flags->data[i] = 0;
        }

    }
    return pBit_flags;

}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    int j, i;
    unsigned int big_num = 2147483648;
    int* temp;
    if ((flag_position / 32) >= (pBit_flags->capacity))
    {
        temp = (int*)malloc(sizeof(int)*(flag_position / 32 + 1));
        if (temp == NULL) {
            return FAILURE;
        }
        for (i = 0; i < (flag_position / 32 + 1); i++) {

            temp[i] = 0;
        }
        for (j = 0; j < pBit_flags->capacity; j++)
        {
            temp[j] = pBit_flags->data[j];
        }
        free(pBit_flags->data);
        pBit_flags->data = NULL;
        pBit_flags->data = temp;
        pBit_flags->capacity = flag_position / 32 + 1;
    }
    pBit_flags->data[flag_position / 32] = (pBit_flags->data[flag_position / 32])| (big_num >> (flag_position % 32));
    return SUCCESS;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
    free(pBit_flags->data);
    free(pBit_flags);
    *phBit_flags = NULL;
}