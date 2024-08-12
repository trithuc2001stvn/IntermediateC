// CH14:partition.c
#include <stdio.h>
#include <stdlib.h>
int func(int n)
{
	if (n == 1 )
		return 1;
	return (2 * func(n-1));
}
int main (int argc, char ** argv)
{
	if (argc < 2)
	{
		printf("Need provide number");
		return EXIT_FAILURE;
	}
	int num;
	num = (int) strtol(argv[1], NULL, 10);
	int part;
	part = func(num);
	printf("Number partition is %d\n", part);
	return EXIT_SUCCESS;
}
