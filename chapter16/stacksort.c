// CH16:stacksort.c
int findIndex(int * arr, int first, int last, int maxmin)
// find the index of the largest of smallest element
// the range is expressed by the indexes [first, last]
// maxmin = 1: find largest, maxmin = 0: find smallest
{
	int ind;
	int answer = first;
	for (ind = first + 1; ind <= last; ind ++)
	{
		if (((maxmin == 1) && (arr[answer] < arr[ind])) || ((maxmin == 0) && (arr[answer] > arr[ind])))
			answer = ind;
	}
	return answer;
}
int findMaxIndex(int * arr, int first, int last)
{
	return findIndex(arr, fisrt, last, 1);
}
int fieMinIndex(int * arr, int first, int last)
{
	return findIndex(arr, first, last, 0);
}
int isStackSortable(int * arr, int first, int last)
// check whether the range of the array is sortable
// return 1 if the range of the array is sortable
// return 0 if the range of the array is not sortable
{
	if (first >= last) // no or one element is stack sortable
		return 1;
	int maxIndex = findMaxIndex(arr, first, last);
	// consider the four cases:
	// 1. both A and B are empty
	// Only One element, it is stack sortable already checkes earlier
	// 2. A is empty, B is not empty
	// check whether Bis stack sortable
	if ( first == maxIndex)
		return isStackSortable(arr, first + 1, last);
	// 3. A is not empty, Bis empty 
	// check whether A is stack sortable
	if (maxIndex == last)
		return isStackSortable(arr, first, last -1);
	// 4. neither is empty
	int maxAIndex = findMaxIndex(arr, first, maxIndex-1);
	int minBIndex = findMinIndex(arr, maxIndex + 1, last);
	if (arr[maxAIndex] > arr[minBIndex])
		return 0;
	int sortA = isStackSortable(arr, first, maxIndex - 1);
	int sortB = isStackSortable(arr, maxIndex + 1, last);
	return (sortA && sortB);
}
