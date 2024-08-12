// CH14: countfibo1.c
#include <stdio.h>
#include <stdlib.h>
long int fibo1(int n, long int * count)
{
	(* count) ++ ;
	if (n == 1) 
		return 1;
	if (n == 2)
		return 1;
	long int a = fibo1(n-1, count);
	long int b = fibo1(n-2, count);
	return a + b;
}
int main(int argc, char ** argv)
{
	int n;
	for (n = 2; n <= 40; n++)
	{
		long int count = 0;
		long int result = fibo1(n, & count);
		printf("n = %d, result = %ld, count = %ld\n", n, result, count);
	}
	return EXIT_SUCCESS;
}


