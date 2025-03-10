// CH10:fscanf.c
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char ** argv)
{
	if (argc != 2 )
	{
		printf("Need provide file's names");
		return EXIT_FAILURE;
	}
	FILE * fptr;
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("Fail open file");
		return EXIT_FAILURE;
	}
	int ind;
	// call fgetc 5 times
	for (ind = 0; ind < 5; ind ++)
	{
		int ch = fgetc(fptr);
	}
	printf("ftell = %ld\n", ftell(fptr));
	fseek(fptr, 0, SEEK_SET);
	// call fscanf %d five times
	for (ind = 0; ind < 5; ind ++)
	{
		int val;
		if (fscanf(fptr, "%d", & val) == 1)
		{
			printf("val = %d\n", val);
		}
	}
	printf("ftell = %ld\n", ftell(fptr));
	int ch = fgetc(fptr);
	printf("ch  = %d, '%c' \n", ch, ch);
	fseek(fptr, 0, SEEK_SET);
	// call fscanf %lf five times
	for (ind = 0; ind < 5; ind ++)
	{
		double val;
		if (fscanf(fptr, "%lf", & val) == 1)
		{
			printf("val = %lf\n", val);
		}
	}
	printf("ftell = %ld\n", ftell(fptr));
	ch = fgetc(fptr);
	printf("ch = %d, '%c'\n", ch, ch);
	fclose(fptr);
	return EXIT_SUCCESS;
}
