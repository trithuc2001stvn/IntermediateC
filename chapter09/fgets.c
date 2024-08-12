// CH09:fgets.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 81
int main(int argc, char ** argv)
{
	FILE * fptr;
	int numLine = 0;
	char oneLine[MAX_LINE_LENGTH];
	if (argc < 2)
	{
		printf("Need provide a file's name.");
		return EXIT_FAILURE;
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("Fail open file");
		return EXIT_FAILURE;
	}
	printf("The name of the file is %s.\n", argv[1]);
	while (fgets(oneLine, MAX_LINE_LENGTH, fptr) != NULL)
	{
		numLine ++;
	}
	fclose(fptr);
	printf("The file has %d lines.\n", numLine);
	return EXIT_SUCCESS;
}
