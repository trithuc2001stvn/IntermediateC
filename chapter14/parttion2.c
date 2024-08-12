// CH14:partition2.c
#include <stdio.h>
#include <stdlib.h>
int func (int n)
{
	int i, sum = 0;
	if (n == 1) 
		return 1;
	for (i = 1; i < n; i ++)
	{
		sum += func(n-i);
	}
	sum ++;
	return sum;
}
int main(int argc, char ** argv)
{
	int n;
	if (argc < 2)
	{
		printf("Need one positive interger\n");
		return EXIT_FAILURE;
	}
	n = (int) strtol(argv[1], NULL, 10);
	if (n < 0)
	{
		printf("Need one positive interger\n");
		return EXIT_FAILURE;
	}
	printf("f(%d) = %d\n", n, func(n));
	return EXIT_SUCCESS;
}
