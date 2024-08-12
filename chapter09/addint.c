// CH09: addint.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv)
{
	if (argc < 4) 
	{
		printf("Need more file name");
		return EXIT_FAILURE;
	}
	FILE * fptr1, * fptr2, * fptr3;
	fptr1 = fopen(argv[1], "r");
	if (fptr1 == NULL)
	{
		printf("Fail open file1");
		return EXIT_FAILURE;
	}
	fptr2 = fopen(argv[2], "r");
	if (fptr2 == NULL)
	{
		printf("Fail open file2");
		fclose(fptr1);
		return EXIT_FAILURE;
	}
	fptr3 = fopen(argv[3], "w");
	if (fptr3 == NULL)
	{	
		printf("fail open file3");
		fclose(fptr1);
		fclose(fptr2);
		return EXIT_FAILURE;
	}
	int val1, val2;
	int in1oke = 1, in2oke = 1;
	while (in1oke == 1 || in2oke == 1)
	{
		val1 = 0;
		val2 = 0;
		if (fscanf(fptr1, "%d", & val1) != 1)
			in1oke = 0;
		if (fscanf(fptr2, "%d", & val2) != 1)
			in2oke = 0;
		if (in1oke == 1 || in2oke == 1)
		{
			fprintf(fptr3, "%d\n", val1 + val2);
		}
	}
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return EXIT_SUCCESS;
}
