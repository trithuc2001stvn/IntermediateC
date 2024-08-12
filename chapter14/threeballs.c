// CH14:threeballs.c
#include <stdio.h>
#include <stdlib.h>
int func (int m)
{
	if (m <= 0)
	{
		printf("Invalid number %d, must be positive interger\n", m);
		return -1;
	}
	if (m == 1) return 3;
	if (m == 2) return 8;
	return ((2 * func(m-1)) + (2 * func(m-2)));
}
int main(int argc, char ** argv)
{
	int c, n;
	if (argc < 2)
	{
		printf("Need provide positive interger\n");
		return EXIT_FAILURE;
	}
	n = (int) strtol(argv[1], NULL, 10);
	c = func(n);
	printf("F(%d) = %d.\n", n, c);
	return EXIT_SUCCESS;
}
