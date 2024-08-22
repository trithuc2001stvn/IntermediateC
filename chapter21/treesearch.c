// CH21:treesearch.c
#include "tree.h"
TreeNode * Tree_search(TreeNode * tn, int val)
{
	if (tn == NULL)
		return NULL;
	if ((tn -> value) == val)
		return tn;
	if (val < (tn -> value))
		return Tree_search(tn -> left, val);
	return Tree_search(tn -> right, val);
//		tn = Tree_search(tn -> left, val);
//	else
//		tn = Tree_search(tn -> right, val);
//	return tn;
}
