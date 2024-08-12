// CH009: fscanfstr.c
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
int main (int argc, char ** argv)
{
	FILE * fptr;
	if (argc < 2)
	{
		printf("Need to provide the file name.");
		return EXIT_FAILURE;
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("Fail open file.");
		return EXIT_FAILURE;
	}
	char buffer[MAX_SIZE];
	while (fscanf(fptr, "%s", buffer) == 1)
	{
		printf("%s\n", buffer);
	}
	fclose(fptr);
	return EXIT_SUCCESS;
}
