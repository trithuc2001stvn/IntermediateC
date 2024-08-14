// CH17:personprint.c
#include <stdio.h>
#include <stdlib.h>
#include "person.h"
void Person_print(Person * p)
{
	printf("Date of Birth: %d/%d/%d.\n", p -> date, p -> month, p -> year);
	printf("Name: %s. \n", p -> name);
}

