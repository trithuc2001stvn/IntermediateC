// CH17:person1.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
int main(int argc, char ** argv)
{
	Person * p1 = Person_construct(1990, 1, 1, "Alice");
	Person * p2 = Person_construct(2000, 20, 7, "Bob");
	Person_print(p1);
	Person_print(p2);
	Person_destruct(p1);
	Person_destruct(p2);
	return EXIT_SUCCESS;
}
