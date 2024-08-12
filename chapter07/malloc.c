// CH07: malloc.c
// create an array whose size is specified at run time. the array's
// elements are the command line arguments. The program adds the
// elements and print the sum.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv)
{
	int * arr2;
	int iter;
	int sum =0;
	if (argc < 2)
	{
		printf("Need to provide some intergers\n");
		return EXIT_FAILURE;
	}
	arr2 = malloc(argc * sizeof(int));
	if (arr2 == NULL)
	{
		printf("Malloc fails.\n");
		return EXIT_FAILURE;
	}
	for (iter = 1; iter < argc; iter ++)
	{
		arr2[iter] = (int) strtol(argv[iter], NULL, 10);
	}
	printf("The sum of ");
	for (iter = 1; iter < argc; iter ++)
	{
		printf("%d ", arr2[iter]);
		sum += arr2[iter];
	}
	printf("is %d.\n", sum);
	free(arr2);
	return EXIT_SUCCESS;
}
