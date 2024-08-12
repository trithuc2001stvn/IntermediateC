// CH10:sortint.c
#include <stdio.h>
#include <stdlib.h>

int comparefunc(const void * arg1, const void * arg2)
{
	const int * ptr1 = (const int *) arg1;
	const int * ptr2 = (const int *) arg2;
	int val1 = * ptr1;
	int val2 = * ptr2;
	if (val1 < val2)
		return -1;
	if (val1 == val2)
		return 0;
	return 1;
}
int main (int argc, char ** argv)
{
	if (argc < 3)
	{
		printf("Need provide input file and output file");
		return EXIT_FAILURE;
	}
	FILE * infptr;
	infptr = fopen(argv[1], "r");
	if (infptr == NULL)
	{
		printf("Fail open input file");
		return EXIT_FAILURE;
	}
	int val, count = 0;
	while (fscanf(infptr, "%d", & val) == 1)
		count ++ ;
	int * array;
	array = malloc(sizeof(int) * count);
	if (array == NULL)
	{
		printf("Fail allocate memory");
		fclose(infptr);
		return EXIT_FAILURE;
	}
	fseek(infptr, 0, SEEK_SET);
	count = 0;
	while (fscanf(infptr, "%d", & val) == 1)
	{
		array[count] = val;
		count ++ ;
	}
	qsort(array, count, sizeof(int), comparefunc);
	fclose(infptr);
	FILE * outfptr;
	outfptr = fopen (argv[2], "w");
	if (outfptr == NULL)
	{
		printf("Fail open output file");
		free(array);
		return EXIT_FAILURE;
	}
	for (val = 0; val < count; val ++)
		fprintf(outfptr, "%d\n", array[val]);
	fclose(outfptr);
	free(array);
	return EXIT_SUCCESS;
}

