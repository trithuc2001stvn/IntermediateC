// CH20:sparse.h
#ifndef SPARSE_H
#define SPARSE_H
typedef struct linked
{
	int index;
	int value;
	struct linked * next;
} Node;
// rea a sparse array from a file and return array
// return NULL if reading fails
Node * List_read(char * filename);
// write a sparse array to a file, return 1 if success, 0 if fail
int List_save(char * filename, Node * arr);
// merge two sparse array not changed and the new array
// does not share memory with the input arrays
Node * List_merge(Node * arr1, Node * arr2);
// release all nodes in a sparse array
void List_destroy(Node * arr);
#endif
