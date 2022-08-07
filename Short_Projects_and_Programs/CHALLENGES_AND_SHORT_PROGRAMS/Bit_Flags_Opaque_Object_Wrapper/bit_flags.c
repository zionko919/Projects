/***********************************************************
Purpose: Making Space for Bits using Dynamic Data Structure

The first is that the resizing operation gets expensive as it gets larger.
A linked list may be better suited for this purpose.
I would create a function that would resize the size,
since I made it so that the capacity of the data structure
is no more than 4 bytes than the actual size at all times. So even if
the bit_flags is offset by slightly little it still needs to resize. I
could have chosen to double in size every iteration, but the benefit of
this method is that it conserves on the memory instead, at the cost of
frequent resizing.
***********************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "bit_flags.h"



struct my_bit_flags
{
    int size;
    int capacity;
    int* bits;
};
typedef struct my_bit_flags My_bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    My_bit_flags* pBit_flags = (My_bit_flags*)malloc(sizeof(My_bit_flags));
    int num_bits = (sizeof(int)*8);
    if (pBit_flags != NULL){
        pBit_flags->size = number_of_bits;
        pBit_flags->capacity = number_of_bits / num_bits * num_bits + num_bits;
        pBit_flags->bits = (int*)malloc(sizeof(int) * pBit_flags->capacity);
        if (pBit_flags->bits == NULL){
            free(pBit_flags);
            return NULL;
        }
    }
    return pBit_flags;
}

Status bit_flags_set_flags(BIT_FLAGS hBit_flags, int flag_position)
{
    My_bit_flags* pBit_flags = (My_bit_flags*)hBit_flags;
    int num_bits = (sizeof(int)*8);
    int arr_num = flag_position / num_bits;
    int arr_position = flag_position % num_bits;
    unsigned int i; int* temp;
    if (flag_position > bit_flags_get_capacity(hBit_flags)) {
        temp = (int*)malloc(sizeof(int) * arr_num + 1);
        if (temp == NULL) {
            return FAILURE;
        }
        for (i = 0; i < arr_num; i++) {
            if (i < (bit_flags_get_capacity(hBit_flags) / num_bits)) {
                temp[i] = pBit_flags->bits[i];
            }
        }
        pBit_flags->size = (flag_position + 1);
        pBit_flags->capacity = (flag_position + 1) / num_bits * num_bits + num_bits;
        temp[arr_num] = temp[arr_num] | (1 << arr_position);
        pBit_flags->bits = temp;
        return SUCCESS;
    }
    pBit_flags->bits[arr_num] = pBit_flags->bits[arr_num] | (1 << arr_position);
    pBit_flags->size = (flag_position + 1);
    hBit_flags = pBit_flags;
    return SUCCESS;
}

Status bit_flags_unset_flags(BIT_FLAGS hBit_flags, int flag_position)
{

    My_bit_flags* pBit_flags = (My_bit_flags*)hBit_flags;
    int num_bits = (sizeof(int)*8);
    int arr_num = flag_position / num_bits;
    int arr_position = flag_position % num_bits;
    int i; int* temp;
    if (flag_position > bit_flags_get_capacity(hBit_flags)) {
        temp = (int*)malloc(sizeof(int) * arr_num + 1);
        if (temp == NULL) {
            return FAILURE;
        }
        for (i = 0; i < arr_num; i++) {
            if (i < (bit_flags_get_capacity(hBit_flags) / num_bits)) {
                temp[i] = pBit_flags->bits[i];
            }
        }
        pBit_flags->size = flag_position;
        pBit_flags->capacity = flag_position / num_bits * num_bits + num_bits;
        temp[arr_num] = temp[arr_num] &~ (1 << flag_position);
        pBit_flags->bits = temp;
        return SUCCESS;
    }
    pBit_flags->bits[arr_num] = pBit_flags->bits[arr_num] &~ (1 << arr_position);
    hBit_flags = pBit_flags;
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    My_bit_flags* pBit_flags = (My_bit_flags*)hBit_flags;
    int flag_value = 0;
    int num_bits = (sizeof(int)*8);
    int arr_num = flag_position / num_bits;
    if (flag_position < pBit_flags->capacity) {
        if (pBit_flags->bits[arr_num] & (1 << flag_position)) {
            flag_value =1;
        }
        return flag_value;
    } else {
        return -1;
    }

}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    My_bit_flags* pBit_flags = (My_bit_flags*)hBit_flags;
    return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    My_bit_flags* pBit_flags = (My_bit_flags*)hBit_flags;
    return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
    My_bit_flags* pBit_flags = (My_bit_flags*)*phBit_flags;
    free(pBit_flags->bits);
    free (pBit_flags);
    *phBit_flags = NULL;
}

