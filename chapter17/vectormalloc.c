// CH17:vectormalloc.c
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
Vector * Vector_construct(int a, int b, int c)
{
	Vector * v;
	v = malloc(sizeof(Vector)); // pay attention of size of
	if (v == NULL) // allocation fail
	{
		printf("Malloc fail.\n");
		return NULL;
	}
	v -> x = a;
	v -> y = b;
	v -> z = c;
	return v;
}
void Vector_deconstruct(Vector *v)
{
	free(v);
}
void printVector(Vector *v)
{
	printf("The vector is (%d, %d, %d).\n", v -> x, v -> y, v -> z);
}
int main(int argc, char ** argv)
{
	Vector * v1;
	v1 = Vector_construct(3, 6, -2);
	// Rl
	if (v1 == NULL)
		return EXIT_FAILURE;
	printVector(v1);
	Vector_deconstruct(v1); // remember to free
	return EXIT_SUCCESS;
}


