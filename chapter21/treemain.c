// CH21:treemain.c
#include <stdio.h>
#include <stdlib.h>
#include "treeinsert.c"
#include "treeprint.c"
#include "treeheight.c"
#include "countnode.c"
int main(int argc, char ** argv)
{
	TreeNode * root = NULL;
	root = Tree_insert(root, 8);
	root = Tree_insert(root, 4);
	root = Tree_insert(root, 3);
	root = Tree_insert(root, 7);
	root = Tree_insert(root, 6);
	root = Tree_insert(root, 5);
	root = Tree_insert(root, 9);
	for (int i = 11; i < 18; i ++)
	{
		root = Tree_insert(root, i);
	}
	Tree_print(root);
	int h, n = 0;
	h = Tree_Height(root, 0);
	n = Count_node(root, &n);
	printf("Node: %d\n", n);
	printf("Heigh: %d\n", h);
	return EXIT_SUCCESS;
}	
