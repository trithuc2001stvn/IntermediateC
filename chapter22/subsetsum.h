// CH22:subsetsum.h
#ifndef SUBSETSUM_H
#define SUBSETSUM_H
#include <stdio.h>
int subsetEqual(int * setA, int sizeA, int kval, unsigned int code);
// return 1 if the subset expressed by the code sum to kval
// return 0 if the sum is different form kval
int subsetSumZ(int * setA, int sizeA, int kval);
// the number of subsets in setA equal
int isValidSet(int * setA, int sizeA);
// valid if elements are positive and distinct
// return 1 if valid, 0 if invalid
int countInterger(FILE * fptr);
// how many intergers in a file
// fptr must not be NULL, checked by the caller
#endif
