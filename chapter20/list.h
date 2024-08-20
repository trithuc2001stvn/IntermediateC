// CH20:list.h
#ifndef LIST_H
#define LIST_H
typedef struct listnode
{
	struct listnode * next;
	int value;
} Node;
Node * List_insert(Node * head, int val);
void List_print(Node * head);
void List_destroy(Node * head);
#endif
