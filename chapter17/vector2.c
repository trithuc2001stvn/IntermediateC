// CH17: vector2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
int equalVector(Vector v1, Vector v2)
{
	if (v1.x != v2.x)
		return 0;
	if (v1.y != v2.y)
		return 0;
	if (v1.z != v2.z)
		return 0;
	return 1;
}
int main(int argc, char ** argv)
{
	Vector v1;
	v1.x = 3;
	v1.y = 6;
	v1.z = -2;
	printf("The vector1 is (%d, %d, %d).\n", v1.x, v1.y, v1.z);
	Vector v2 = {0};
	printf("The vector2 is (%d, %d, %d).\n", v2.x, v2.y, v2.z);
	v2 = v1;
	printf("The vector2 copy is (%d, %d, %d).\n", v2.x, v2.y, v2.z);
	v1.x = -4;
	v2.y = 5;
	printf("The vector1 is (%d, %d, %d).\n", v1.x, v1.y, v1.z);
	printf("The vector2 is (%d, %d, %d).\n", v2.x, v2.y, v2.z);
	return EXIT_SUCCESS;
}

