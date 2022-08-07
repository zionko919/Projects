#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"


#define NUMBER_OF_BITS 20

int main(int argc, char* argv[]){


	BIT_FLAGS hBit_flags = NULL;
	int i;

	hBit_flags = bit_flags_init_number_of_bits(NUMBER_OF_BITS);
	if (hBit_flags == NULL)
	{
		printf("out of memory??\n");
		exit(1);
	}

	// see if their size and capacity are correct for the init.
	printf("Expecting 20/32 for 32 bit integers \n");
	printf("size / capacity: %d / %d\n\n", bit_flags_get_size(hBit_flags),
		bit_flags_get_capacity(hBit_flags));

	bit_flags_set_flag(hBit_flags, 40);

	//see if their size and capacity change when setting a flag out of bounds
	printf("Expecting 41/64 for 32 bit integers \n");
	printf("size / capacity: %d / %d\n\n", bit_flags_get_size(hBit_flags),
		bit_flags_get_capacity(hBit_flags));

	//see if their size and capacity change when unsetting a flag out of bounds
	bit_flags_unset_flag(hBit_flags, 70);
	printf("Expecting 71/96 for 32 bit integers \n");
	printf("size / capacity: %d / %d\n\n", bit_flags_get_size(hBit_flags),
		bit_flags_get_capacity(hBit_flags));

	//set flag 3
	bit_flags_set_flag(hBit_flags, 3);

	//check flag 3
	printf("Flag three is expecting 1. Got: %d\n", bit_flags_check_flag(hBit_flags, 3));

	//unset flag 3
	bit_flags_unset_flag(hBit_flags, 3);
	
	//check flag 3
	printf("Flag three is expecting 0. Got: %d\n", bit_flags_check_flag(hBit_flags, 3));


	//verify with valgrind that there is no memory leak after clean up.
	bit_flags_destroy(&hBit_flags);

	return 0;

}