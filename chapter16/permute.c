// CH16:permute.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printArray(int * arr, int length)
{
	int ind;
	for (ind = 0; ind < length - 1; ind ++)
	{
		printf("%c ", arr[ind]);
	}
	printf("%c\n", arr[length - 1]);
}
void swap(int * a, int * b)
{
	int t = * a;
	* a = * b;
	* b = t;
}
void permuteHelp(int * arr, int ind, int num)
{
	if (ind == num)
	{
		printArray(arr, num);
		return;
	}
	int loc;
	for (loc = ind; loc < num; loc ++)
	{
		swap(& arr[ind], & arr[loc]);
		permuteHelp(arr, ind + 1, num);
		swap(& arr[ind], & arr[loc]);
	}
}
void permute(int * arr, int num)
{
	permuteHelp(arr, 0, num);
}
int main(int argc, char ** argv)
{
	if (argc < 2)
		return EXIT_FAILURE;
	int num = strtol(argv[1], NULL, 10);
	if (num <= 0)
		return EXIT_FAILURE;
	int * arr;
	arr = malloc(sizeof(int) * num);
	if (arr == NULL)
		return EXIT_FAILURE;
	int ind;
	for (ind = 0; ind < num; ind ++)
		arr[ind] = ind + 'A';
	permute(arr, num);
	free(arr);
	return EXIT_SUCCESS;
}

