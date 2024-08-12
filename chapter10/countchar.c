// CH10:countchar.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUMBER_CHARACTER 26
int main (int argc, char ** argv)
{
	if (argc < 3)
	{
		printf("Need provide more file name");
		return EXIT_FAILURE;
	}
	FILE * infptr;
	infptr = fopen(argv[1], "r");
	if (infptr == NULL)
	{
		printf("Fail open input file");
		return EXIT_FAILURE;
	}
	char arr[NUMBER_CHARACTER] ={0};
	char oneChar;
	do
	{	
		oneChar = fgetc(infptr);
		if (isupper(oneChar))
			arr[oneChar - 'A'] ++ ;
		if (islower(oneChar))
			arr[oneChar - 'a'] ++ ;
	} while (oneChar != EOF);
	fclose(infptr);
	FILE * outfptr;
	outfptr = fopen(argv[2], "w");
	if (outfptr == NULL)
	{
		printf("Fail open output file");
		return EXIT_FAILURE;
	}
	int ind;
	for (ind =0; ind < NUMBER_CHARACTER; ind ++)
	{
		if (arr[ind] != 0)
		{
			printf("%c : %d\n", (ind + 'a'), arr[ind]);
		}
	}
	fclose(outfptr);
	return EXIT_SUCCESS;
}
