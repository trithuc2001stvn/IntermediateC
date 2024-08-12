// CH14:countfibo2.c
#include <stdio.h>
#include <stdlib.h>
long int fibo2(int n, long int * count)
{
	(* count) ++ ;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	long int a;
	long int b;
	int m = n/2;
	if ((n % 2) == 0)
	{
		b = fibo2(m, count);
		long int c = fibo2(m-1, count);
		a = b + c;
		return (a * b + b * c);
	}
	a = fibo2(m + 1, count);
	b = fibo2(m, count);
	return (a * a + b * b);
}
int main(int argc, char ** argv)
{
	int n;
	for (n = 2; n <= 40; n++)
	{
		long int count = 0;
		long int result = fibo2(n, & count);
		printf("n = %d, result = %ld, count = %ld\n", n, result, count);
	}
	return EXIT_SUCCESS;
}
