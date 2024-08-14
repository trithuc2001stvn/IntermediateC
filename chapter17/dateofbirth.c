// CH17:dateofbirth.c
#include <stdio.h>
#include "dateofbirth.h"
DateOfBirth DateOfBirth_construct(int y, int m, int d)
{
	DateOfBirth dob;
	dob.year = y;
	dob.month = m;
	dob.date = d;
	return dob;
}
void DateOfBirth_print(DateOfBirth dob)
{
	printf("Date of Birth: %d/%d/%d\n", dob.year, dob.month, dob.date);
}
