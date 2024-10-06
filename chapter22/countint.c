// CH22:countint.c
#include <stdio.h>
int countInterger(FILE * fptr)
{
	int numInt = 0; // how many intergers
	int value;
	while (fscanf(fptr, "%d", & value))
	{
		numInt ++;
	}
	return numInt;
}

