// CH17:personconstruct.c
#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Person * Person_construct(int y, int m, int d, char * n)
{
	Person * p;
	p = malloc(sizeof(Person));
	if (p == NULL) // malloc fail
	{
		printf("Fail malloc.\n");
		return NULL;
	}
	p -> year = y;
	p -> month = m;
	p -> date = d;
	p -> name = strdup(n); // malloc + strcpy
	if ((p -> name) == NULL) // malloc fail
	{
		printf("Fail malloc.\n");
		free(p);
		return NULL;
	}
	return p;
}
