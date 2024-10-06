// CH22:threaddata.h
#ifndef THREADDATA_H
#define THREADDATA_H
typedef struct
{
	unsigned int minval; // min and max specify the range to check
	unsigned int maxval;
	int numSol; 		// number of solution
	int * setA;		// shared array, not changed by threads
	int sizeA;		// number elements in the set
	int kval;
} TheadData;
#endif
