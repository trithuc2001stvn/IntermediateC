// CH21:treeheight.c
#include "tree.h"
#include <stdio.h>
int Tree_Height(TreeNode * tn, int m)
{
	if (tn == NULL)
		return m;
	m ++;
	int ml = Tree_Height(tn -> left, m); 
	int mr = Tree_Height(tn -> right, m);
	if (ml >= mr)
		return ml;
	return mr;
}
