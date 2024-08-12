// CH14: tower.c
#include <stdio.h>
#include <stdlib.h>

int func (int n)
{
	if (n == 1)
		return 1;
	return (2 * func(n-1) +1);
}
int main (int argc, char ** argv)
{
	if (argc < 2)
	{
		printf("Need provide number of disk\n");
		return EXIT_FAILURE;
	}
	int num;
	num = (int) strtol(argv[1], NULL, 10);
	int step;
	step = func(num);
	printf("Need %d steps to move %d disk from A to B\n", step, num);
	return EXIT_SUCCESS;
}
