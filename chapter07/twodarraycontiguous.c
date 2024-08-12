// CHO07: twodarraycontiguous.c
// purpose: show how to create a two-dimensional array. The size of
// the array is 8 row x 3 columns
// this version ensures that the allocation is contiguous.
// That is, all of the "rows" are located in a single allocated block of memory
#include <stdio.h>
#include <stdlib.h>
#define NUMROW 8
#define NUMCOLUMN 3
int main(int argc, char * argv[])
{
	int * * arr2d;
	int * arr2d_data;
	int row;

	arr2d = malloc(NUMROW * sizeof(int*));

	arr2d_data = malloc(NUMROW * NUMCOLUMN * sizeof(int));
	for (row = 0; row < NUMROW; row ++)
	{
		arr2d[row] = arr2d_data + row * NUMCOLUMN;
	}
	arr2d[4][1] = 100;
	arr2d[7][0] = -34;

	free(arr2d);
	free(arr2d_data);
	return EXIT_SUCCESS;
}

