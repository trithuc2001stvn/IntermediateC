// CH17:person6.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dateofbirth.h"
#include "person6.h"
int main(int argc, char ** argv)
{
	Person * p1 = Person_construct("Ami", 1990, 3, 20);
	Person * p2 = Person_construct("Bob", 2000, 4, 30);
	Person * p3 = Person_copy(p1);
	Person_print(p1);
	Person_print(p2);
	Person_print(p3);
	p3 = Person_assign(p3, p2); // change p3
	Person_print(p3);
	Person_destruct(p1);
	Person_destruct(p2);
	Person_destruct(p3);
	return EXIT_SUCCESS;
}
Person * Person_construct(char * name, int y, int m, int d)
{
	Person * p;
	p = malloc(sizeof(Person));
	if (p == NULL)
	{
		printf("Fail malloc\n");
		return NULL;
	}
	p -> name = strdup(name);
	p -> dob = DateOfBirth_construct(y, m, d);
	return p;
}
void Person_destruct(Person * p)
{
	// p must be released after p -> name has been released
	free(p -> name);
	free(p);
}
Person * Person_copy(Person * p)
{
	return Person_construct(p -> name, p -> dob.year, p -> dob.month, p -> dob.date);
}
Person * Person_assign(Person * p1, Person * p2)
{
	free(p1 -> name);
	p1 -> name = strdup(p2 -> name);
	p1 -> dob = p2 -> dob;
	return p1;
}
void Person_print(Person * p)
{
	printf("Name: %s. ", p -> name);
	DateOfBirth_print(p -> dob);
}
