// CH08: sort/bubblesort.cc
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARRAY_SIZE 100
static void swap(int * a, int * b)
{
	int t = * a;
	* a = * b;
	* b = t;
}
void bubble(int * arr, int len)
{

	int ind1, ind2;
	int count = 0;
	for (ind1 = 0; ind1 < len; ind1 ++)
	{
		for (ind2 = ind1 + 1; ind2 < len; ind2 ++)
		{
			if (arr[ind1] > arr[ind2])
			{
				swap(& arr[ind1], & arr[ind2]);
				count ++;

			}
		}
	}
	printf("swap is called %d times\n", count);
}
void printArray(int * array, int len)
{
	int ind;
	for (ind=0; ind < len; ind++)
	{
		printf("%d ", array[ind]);
	}
	printf("\n");
}
int main(int argc, char ** argv)
{
	int arr[ARRAY_SIZE];
	int ind;
	for(ind = 0; ind < ARRAY_SIZE; ind ++)
		arr[ind] = ind;
	printArray(arr, ARRAY_SIZE);
	bubble(arr, ARRAY_SIZE);
	printArray(arr, ARRAY_SIZE);
	return EXIT_SUCCESS;
}

