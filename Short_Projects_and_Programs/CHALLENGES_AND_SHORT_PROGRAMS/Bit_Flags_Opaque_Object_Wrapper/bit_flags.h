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

#ifndef BIT_FLAGS_H
#define BIT_FLAGS_H
#include "status.h"

typedef void* BIT_FLAGS;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);

Status bit_flags_set_flags(BIT_FLAGS hBit_flags, int flag_position);

Status bit_flags_unset_flags(BIT_FLAGS hBit_flags, int flag_position);

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);

int bit_flags_get_size(BIT_FLAGS hBit_flags);

int bit_flags_get_capacity(BIT_FLAGS hBit_flags);

void bit_flags_destroy(BIT_FLAGS* phBit_flags);

#endif
