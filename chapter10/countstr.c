// CH10:countstr.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 81
int main(int argc, char ** argv)
{
	if (argc < 4)
	{
		printf("Need provide more argruments");
		return EXIT_FAILURE;
	}
	FILE * infptr;
	infptr = fopen(argv[1], "r");
	if (infptr == NULL)
	{
		printf("Fail open input file");
		return EXIT_FAILURE;
	}
	FILE * outfptr;
	outfptr = fopen(argv[2], "w");
	if (outfptr == NULL)
	{
		printf("Fail open output file");
		fclose(infptr);
		return EXIT_FAILURE;
	}
	char oneLine[MAX_LINE_LENGTH];
	int count = 0;
	while (fgets(oneLine, MAX_LINE_LENGTH, infptr) != NULL)
	{
		if (strstr(oneLine, argv[3]) != NULL)
		{
			fprintf(outfptr, "%s", oneLine);
		}
		char * strptr;
		strptr = oneLine;
		while (strptr != NULL)
		{
			strptr = strstr(strptr, argv[3]);
			if (strptr != NULL)
			{
				count ++ ;
				strptr ++ ;
			}
		}
		char * ptr;
		ptr = oneLine;
		int ind = 0, prev, next;
		while (ptr[ind] != '\0')
		{
			int idx = 0;
			prev = ind ;
			next = ind + 2;
			while ((prev >= 0) && (next < MAX_LINE_LENGTH) && (ptr[prev] == ptr[next]))
			{
				prev -- ;
				next ++ ;
			}
			prev = prev + 1;
			next = next - 1;
			if ((ptr[prev] == ptr[next]) && (next - prev) >= 2)
			{
				for (idx = prev; idx <= next; idx ++)
				printf("%c",ptr[idx]);
			}
			ind ++ ;
		}
		printf("\n");
	}
	fprintf(outfptr, "%d\n", count);
	fclose(infptr);
	fclose(outfptr);
	return EXIT_SUCCESS;
}
