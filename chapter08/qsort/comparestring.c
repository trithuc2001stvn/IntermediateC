// CH08: qsort/comparestring.c
#include <string.h>
int comparestring(const void * arg1, const void * arg2)
{
	const char * * ptr1 = (const char * *) arg1;
	const char * * ptr2 = (const char * *) arg2;
	const char * str1 = * ptr1;
	const char * str2 = * ptr2;
	return strcmp(str1, str2);
}

