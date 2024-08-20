// CH20:listreverse.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
Node * List_reverse(Node * head)
{
	if (head == NULL)
		return NULL;
	Node * orighead = head;
	Node * revhead = NULL; // must initialize to NULL
	Node * origsec = NULL; // will be updated before using
	while (orighead != NULL)
	{
		origsec = orighead -> next;
		orighead -> next = revhead;
		revhead = orighead;
		orighead = origsec;
	}
	return revhead;
}
int main(int argc, char ** argv)
{
	Node * head = NULL;
	head = List_insert(head, 1);
	head = List_insert(head, 2);
	head = List_insert(head, 3);
	head = List_insert(head, 4);
	List_print(head);
	head = List_reverse(head);
	List_print(head);
	return EXIT_SUCCESS;
}
