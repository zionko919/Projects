/***********************************************
    Self Learning C - Basic 20
 ***********************************************/

#include <stdio.h>

int printArrayValues(int array_of_integers[], int size_of_array);
void fillWithIndex(int array_of_integers[], int size_of_array );

int main(int argc, char * argv[])
{
    int arr1[] = {23, 21, 20, 27};
    int arr2[] = {5, 7, 9, 11, 13};

    printArrayValues(arr1, 4);
    fillWithIndex(arr1, 4);
    printArrayValues(arr1, 4);

    printArrayValues(arr2, 5);
    fillWithIndex(arr2, 5);
    printArrayValues(arr2, 5);

    return 0;
}

int printArrayValues(int array_of_integers[], int size_of_array)
{
	int i;
	int values;

	values = 0;

	for (i = 0; i < size_of_array; i++){
		values =  array_of_integers[i];
		printf("%d ", values);

	}
	printf("\n");

	return values;
}

void fillWithIndex(int array_of_integers[], int size_of_array )
{
    int i;
    for (i = 0; i < size_of_array; i++){
        array_of_integers[i] = i; // replaceing elements with index. +1 to increase the index number
    }
    return;
}

