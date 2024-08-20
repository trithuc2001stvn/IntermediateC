// CH19:listsearch.c
#include "list.h"
#include <stdio.h>
Node * List_search(Node * head, int val)
	// head: the head node of the linked list
	// val: the value to search
	// If any node stores val, this function return that node
	// If multiple nodes store val, this function return the node
	// closest to the head.
	// If no node stores val, this function return NULL
{
	Node * ptr = head;
	while (ptr -> next != NULL)
	{
		if (ptr -> value == val)
			return ptr;
		ptr = ptr -> next;
	}
	return ptr; // must be NULL now
}

