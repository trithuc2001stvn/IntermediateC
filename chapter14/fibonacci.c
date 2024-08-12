// CH14:fibonacci.c
#include <stdio.h>
#include <stdlib.h>
#define NUMBER 20
long int fibo1(int n)
{
	if((n == 1) || (n == 2))
		return 1;	
	return (fibo1(n-1) + fibo1(n-2));
}
int main(int argc, char ** argv)
{
	int n;
	for (n = 1; n <= NUMBER; n++)
	{
		printf("%ld ", fibo1(n));
	}
	printf("\n");
	return EXIT_SUCCESS;
}


