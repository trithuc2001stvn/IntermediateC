// CH16: binarysearch.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RANGE 1000
int * genArr (int size);
static int binarySearchHelper(int * arr, int low, int high, int key)
{
	if (low > high)
		return -1;
	int ind = (low + high) / 2;
	if (arr[ind] == key)
		return ind;
	if (arr[ind] > key)
	{
		return binarySearchHelper(arr, low, ind - 1, key);
	}
	return binarySearchHelper(arr, ind + 1, high, key);
}
int binarySearch(int * arr, int len, int key)
{
	return binarySearchHelper(arr, 0, len - 1, key);
}
void printArr(int * arr, int len);
int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		printf("Need a positive interger\n");
		return EXIT_FAILURE;
	}
	int num = strtol(argv[1], NULL, 10);
	if (num <= 0)
	{
		printf("Need a positive interger\n");
		return EXIT_FAILURE;
	}
	int * arr = genArr(num);
	printArr(arr, num);
	int count;
	for (count = 0; count < 10; count ++)
	{
		int key;
		if ((count % 2) == 0)
			key = arr[rand() % num];
		else 
			key = rand() %  100000 ;
		printf("Search(%d), result = %d\n", key, binarySearch(arr, num, key));
	}
	free(arr);
	return EXIT_SUCCESS;
}
int * genArr(int size)
{
	if (size == 0)
		return NULL;
	int * arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return NULL;
	srand(time(NULL));
	int ind;
	arr[0] = rand() % RANGE;
	for (ind =1; ind < size; ind ++)
		arr[ind] = arr[ind - 1] + (rand() % RANGE) + 1;
	return arr;
}
void printArr(int * arr, int len)
{
	int ind;
	for (ind = 0; ind < len; ind ++)
		printf("%d ", arr[ind]);
	printf("\n\n");
}


