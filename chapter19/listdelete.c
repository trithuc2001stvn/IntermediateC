// CH19:listdelete.c
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
Node * List_delete(Node * head, int val)
{
	printf("delete %d\n", val);
	Node * q = head;
	if (q == NULL)
		return NULL;
	// delete head node
	if ((q -> value) == val)
	{
		head = head -> next;
		free(q);
		return head;
	}
	// not deleting the head node
	Node * p = head;
	q = p -> next;
	while ((q != NULL) && (q -> value != val))
	{
		// check whether q is NULL before checking q -> value
		p = p -> next;
		q = q -> next;
	}
	if (q != NULL) // q -> value matches val
	{
		// delete node whose value is val
		p -> next = q -> next;
		free(q);
	}
	return head;
}

