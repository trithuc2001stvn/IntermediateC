// CH16:quicksort.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define RANGE 10000	
static void swap(int * a, int * b)
{
	int s = * a;
	* a = * b;
	* b = s;
}
static void quickSortHelp(int * arr, int first, int last)
{
	// [first, last]: range of valid indexes (not last -1)
	if (first >= last) 
		return;
	int pivot = arr[first];
	int low = first + 1;
	int high = last;
	while (low < high)
	{
		while ((low < last) && (arr[low] <= pivot))
		{
			// <= so that low will increment whe arr[low] is the same
			// as pivo, using < will stop incrementing low when
			// arr[low] is the same as pivot and the outer while loop
			// may not stop
			low ++ ;
		}
		while ((first < high) && (arr[high] > pivot))
		{
			high -- ;
		}
		if (low < high)
		{
			swap(& arr[low], & arr[high]);
		}
	}
	if (pivot > arr[high])
	{
		swap(& arr[first], & arr[high]);
	}
	quickSortHelp(arr, first, high - 1);
	quickSortHelp(arr, low, last);
}
void quickSort(int * arr, int len)
{
	quickSortHelp(arr, 0, len - 1);
}
int * arrGen(int size)
//generate an array of intergers
{
	if (size <= 0)
		return NULL;
	int * arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return NULL;
	int ind;
	for (ind = 0; ind < size; ind ++)
	{
		arr[ind] = rand() % RANGE ;
	}
	return arr;
}
void printArr(int * arr, int len)
{
	int ind;
	int sorted = 1;
	for (ind = 0; ind < len; ind ++)
	{
		printf("%d ", arr[ind]);
		if ((ind > 0) && (arr[ind] < arr[ind -1]))
			sorted = 0;
	}
	printf("\nSorted = %d\n\n", sorted);
}
int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		printf("Need provide a positive interger");
		return EXIT_FAILURE;
	}
	if (argc == 3)
	{
		srand(strtol(argv[2], NULL, 10));
	}
	else 
	{
		srand(time(NULL));
	}
	int num = strtol(argv[1], NULL, 10);
	if (num <= 0)
	{
		printf("Need provide a positive interger");
		return EXIT_FAILURE;
	}
	int * arr = arrGen(num);
	printArr(arr, num);
	quickSort(arr, num);
	printArr(arr, num);
	free(arr);
	return EXIT_SUCCESS;
}
