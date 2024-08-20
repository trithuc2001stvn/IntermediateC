Node * List_insert(Node * head, int val)
{
	if (head == NULL)
		return Node_construct(val);
	Node * p = head;
	while ((P -> next) != NULL)
		p = p-> next;
	p -> next = Node_construct(val);
	return head;
}
