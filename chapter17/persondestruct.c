// CH17:persondestruct.c
#include "person.h"
#include <stdlib.h>
void Person_destruct(Person * p)
{
	free(p -> name); // p -> name must be freed before free p
	free(p);
}	
