// CH21:countnode.c
#include <stdio.h>
#include "tree.h"
int Count_node(TreeNode * tn, int * n)
{
	if (tn == NULL)
		return 0;
	* n = * n + 1;
	Count_node(tn -> left, n);
	Count_node(tn -> right, n);
	return * n;
}
