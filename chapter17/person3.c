// CH17:person3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
int main(int argc, char ** argv)
{
	Person * p1 = Person_construct(1990, 3, 25, "Amiy");
	Person * p2 = Person_construct(2000, 8, 18, "Bob");
	p2 = p1; // discard memory for Bob, leak memory
	Person_print(p1);
	Person_print(p2);
	Person_destruct(p1);
	Person_destruct(p2); // will cause problem
	return EXIT_SUCCESS;
}
