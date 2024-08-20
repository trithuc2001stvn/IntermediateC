// CH19:list.h
#ifndef LIST_H
#define LIST_H
typedef struct listnode
{
	struct listnode * next;
	int value;
} Node; // ; id need
Node * List_insert(Node * head, int val);
Node * List_search(Node * head, int val);
Node * List_delete(Node * head, int val);
void List_print(Node * head);
void List_destroy(Node * head);
#endif
