// CH17:person4.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
int main(int argc, char ** argv)
{
	Person p1; // object, not a pointer
	Person p2;
	p1.year = 1990;
	p1.month = 5;
	p1.date = 28;
	p1.name = "Amiy";
	p2.year = 2000;
	p2.month = 9;
	p2.date = 2;
	p2.name = "Bob";
	Person_print(& p1);
	Person_print(& p2);
	p2 = p1;
	Person_print(& p1);
	Person_print(& p2);
	free(p1.name);
	free(p2.name);
	return EXIT_SUCCESS;
}
