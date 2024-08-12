// CH14:fibonacci2.c
#include <stdio.h>
#include <stdlib.h>
#define NUMBER 20
long int fibo2(int n)
{
	if ((n == 1) || (n == 2)) 
		return 1;
	long int fna = 1;
	long int fnb = 1;
	long int fnc;
	while (n > 2)
	{
		fnc = fnb + fna;
		fna = fnb;
		fnb = fnc;
		n --;
	}
	return fnc;
}
int main(int argc, char ** argv)
{
	int n;
	for (n = 1; n < NUMBER; n ++)
	{
		printf("%ld ", fibo2(n));
	}
	printf("\n");
	return EXIT_SUCCESS;
}
