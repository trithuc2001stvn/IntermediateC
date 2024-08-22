// CH21:treedestroy.c
#include "tree.h"
#include <stdlib.h>
void Tree_destroy(TreeNode * tn)
{
	if (tn == NULL)
		return;
	Tree_destroy(tn -> left);
	Tree_destroy(tn -> right);
	free(tn); // must be after destroying left and right subtrees
}
