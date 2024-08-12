// CH16:combine.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printArray(int * arr, int len)
{
	int ind;
	for (ind = 0; ind < len; ind ++)
	{
		if (arr[ind] == 1)
			printf("%c ", ind + 'A');
	}
	printf("\n");
}
void combineHelp(int * arr, int ind, int num, int toselect, int selected)
{
	if (toselect == selected)
	{
		printArray(arr, num);
		return;
	}
	if (ind == num)
		return;
//	for (int idx = ind; idx < num; idx ++ )
//	{
		arr[ind] = 1;
//		selected += 1;
		combineHelp(arr, ind + 1, num, toselect, selected + 1);
		arr[ind] = 0;
//		selected -= 1;
		combineHelp(arr, ind + 1, num, toselect, selected);
//	}
}
void combine(int * arr, int len, int toselect)
{
	combineHelp(arr, 0, len, toselect, 0);
}
int main(int argc, char ** argv)
{
	if (argc < 3)
	{
		return EXIT_FAILURE;
	}
	int num = (int) strtol(argv[1], NULL, 10);
	if (num <= 0)
		return EXIT_FAILURE;
	int toselect = (int) strtol(argv[2], NULL, 10);
	if ((toselect <= 0) || (toselect > num))
		return EXIT_FAILURE;
	int * arr;
	arr = malloc(sizeof(int) * num);
	if (arr == NULL)
		return EXIT_FAILURE;
	int ind;
	for (ind = 0; ind < num; ind ++)
		arr[ind] = 0;
	combine(arr, num, toselect);
	return EXIT_SUCCESS;
}
	
