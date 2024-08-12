// CH07: twodarray.c
// purpose: show how to create a two-dimensional array. The size of
// the array is 8 row x 3 columns.
#include <stdio.h>
#include <stdlib.h>
#define NUMROW 8
#define NUMCOLUMN 3

int main(int argc, char * argv[])
{
	int * * arr2d;
	int row;
	arr2d = malloc(NUMROW * sizeof(int *));
	for ( row = 0; row < NUMROW; row ++)
	{
		arr2d[row] = malloc(NUMCOLUMN * sizeof(int));
	}
	arr2d[4][1] = 2;
	arr2d[6][2] = 10;
	for (row = 0; row < NUMROW; row ++)
	{
		free(arr2d[row]);
	}
	free(arr2d);
	return EXIT_SUCCESS;
}
