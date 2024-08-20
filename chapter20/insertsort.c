// CH20:innsertsort.c
Node * List_insert(Node * head, int val)
{
	Node * ptr = Node_construct(val);
	if (head == NULL)
		return ptr;
	if ((head -> value) > val)
	{
		ptr -> next = head;
		return ptr;
	}
	// new code is not the head
	Node * q = head;
	Node * r = head -> next; // q is always before r
	while ((r != NULL) && ((r -> value) <= val))
	{
		q = q -> next;
		r = r -> next;
	}
	// new node is between q and r; it is OK r is NULL
	q -> next = ptr;
	ptr -> next = r;
	return head;
}
