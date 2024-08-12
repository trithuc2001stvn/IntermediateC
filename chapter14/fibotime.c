// CH14: fibotime.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 20
#define REPEAT 10000
long int fibo1(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return (fibo1(n-1) + fibo1(n-1));
}
long int fibo2(int n)
{
	if (n == 1 || n == 2) 
		return 1;
	long int fna = 1;
	long int fnb = 1;
	long int fnc;
	while (n > 2)
	{
		fnc = fnb + fna;
		fna = fnb;
		fnb = fnc;
		n -- ;
	}
	return fnc;
}
int main(int argc, char ** argv)
{
	int nval, rept;
	struct timeval time1;
	struct timeval time2;
	float intv1, intv2;
	for (nval = 1; nval < MAX; nval ++)
	{
		long int fval;
		gettimeofday(& time1, NULL);
		for (rept = 0; rept < REPEAT; rept ++)
		{
			fval = fibo1(nval);
		}
		gettimeofday(& time2, NULL);
		intv1 = (time2.tv_sec - time1.tv_sec) + 1e-6 * (time2.tv_usec - time1.tv_usec);
		printf("fibo1 (%2d) = %ld, time = %f\n", nval, fval, intv1);
		gettimeofday(& time1, NULL);
		for (rept = 0; rept < REPEAT; rept ++)
		{
			fval = fibo2(nval);
		}
		gettimeofday(& time2, NULL);
		intv2 = (time2.tv_sec - time1.tv_sec) + 1e-6 * (time2.tv_usec - time1.tv_usec);
		printf("fibo2 (%2d) = %ld, time = %f\n", nval, fval, intv2);
		printf("ratio = %f\n", intv1/intv2);
	}
	return EXIT_SUCCESS;
}

