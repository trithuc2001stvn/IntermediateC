// CH14: tower.c
#include <stdio.h>
#include <stdlib.h>
void move(int n, char src, char dest, char temp)
{
	if (n == 1)
	{
		printf("Move disk 1 from %c to %c\n", src, dest);
		return;
	}
	move((n-1), src, temp, dest);
	printf("Move disk %d from %c to %c\n", n, src, dest);
	move((n-1), temp, dest, src);	
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
	move(num, 'A', 'B', 'C');
	return EXIT_SUCCESS;
}
