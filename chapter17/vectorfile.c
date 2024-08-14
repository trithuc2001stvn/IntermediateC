// CH17:vectorfile.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
Vector Vector_construct(int a, int b, int c)
{
	Vector v;
	v.x = a;
	v.y = b;
	v.z = c;
	return v;
}
void Vector_print(char * name, Vector v)
{
	printf("%s is (%d, %d, %d).\n", name, v.x, v.y, v.z);
}
void Vector_writet(char * filename, Vector v)
{
	FILE * fptr;
	fptr = fopen(filename, "w");
	if (fptr == NULL)
	{
		printf("Vector_writet fopen fail.\n");
		return;
	}
	fprintf(fptr, "%d %d %d", v.x, v.y, v.z);
	fclose(fptr);
}
Vector Vector_readt(char * filename)
{
	Vector v = Vector_construct(0, 0, 0);
	FILE * fptr;
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf("Vector_readt fopen fail.\n");
		return v;
	}
	if (fscanf(fptr, "%d %d %d", & v.x, & v.y, & v.z) != 3)
	{
		printf("fprintf fail.\n");
	}
	fclose(fptr);
	return v;
}
void Vector_writeb(char * filename, Vector v)
{
	FILE * fptr;
	fptr = fopen(filename, "w");
	if (fptr == NULL)
	{
		printf("Vector_writeb fopen fail.\n");
		return;
	}
	if (fwrite(& v, sizeof(Vector), 1, fptr) != 1)
	{
		printf("fwrite fail.\n");
	}
	fclose(fptr);
}
Vector Vector_readb(char * filename)
{
	FILE * fptr;
	Vector v; // not initialized
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf("Vector_readb fopen fail.\n");
		return v;
	}
	if (fread(& v, sizeof(Vector), 1, fptr) != 1)
		printf("fread fail.\n");
	return v;
}
int main(int argc, char ** argv)
{
	Vector v1 = Vector_construct(13, 206, -549);
	Vector v2 = Vector_construct(-15, 8726, 1987);		
	Vector_print("v1", v1);
	Vector_print("v2", v2);
	printf("===============================\n");
	Vector_writet("vectort.dat", v1);
	v2 = Vector_readt("vectort.dat");
	Vector_print("v1", v1);
	Vector_print("v2", v2);
	v1 = Vector_construct(2089, -3357, 1234);
	v2 = Vector_construct(7568, 0, 1876);
	printf("===============================\n");
	Vector_print("v1", v1);
	Vector_print("v2", v2);
	Vector_writeb("vectorb.dat", v1);
	v2 = Vector_readb("vectorb.dat");
	printf("================================\n");
	Vector_print("v1", v1);
	Vector_print("v2", v2);
	return EXIT_SUCCESS;
}
