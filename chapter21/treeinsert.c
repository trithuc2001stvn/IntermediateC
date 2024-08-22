// CH21:treeinsert.c
#include <stdlib.h>
#include "tree.h"
static TreeNode * Tree_construct(int v)
{
	TreeNode * tn;
	tn = malloc(sizeof(TreeNode));
	tn -> left = NULL;
	tn -> right = NULL;
	tn -> value = v;
	return tn;
}
TreeNode * Tree_insert(TreeNode * tn, int val)
{
	if (tn == NULL)
		return Tree_construct(val);
	if ((tn -> value) == val)
		return tn;
	if ((tn -> value) > val)
		tn -> left = Tree_insert(tn -> left, val);
	else
		tn -> right = Tree_insert(tn -> right, val);
	return tn;
}
