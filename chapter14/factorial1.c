// CH14:factorial1.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
long int fac(int n)
{
	if (n < 0) 
	{
		printf("N can be negative interger\n");
		return 0;
	}
	if ( n == 0) 
		return 1;
	return (n * fac(n-1));
}
int main(int argc, char ** argv)
{
	int nval;
	for (nval =0; nval <= MAX; nval ++)
	{
		long int fval = fac(nval);
		printf("fac(%2d) or %2d! = %ld\n", nval, nval, fval);
	}
	return EXIT_SUCCESS;
}
