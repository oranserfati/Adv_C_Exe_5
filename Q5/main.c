#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"

void main() 
{
	BST bst;
	BST* pbst = &bst;
	int N = 7;
	initBST(&bst);
	insertBST(&bst, 4);
	insertBST(&bst, 7);
	insertBST(&bst, 3);
	insertBST(&bst, 5);
	insertBST(&bst, 9);
	insertBST(&bst, 2);
	printTreeInorder(&bst);
	int element = findIndexNFromLast(&bst, N);
	printf("the element is:%d\n", element);
	if (sameHeightLeaves(&bst) == 1)
	{
		printf("Same number of leaves.\n");
	}
	else
		printf("Different number of leaves.\n");
	//print_ascii_tree(pbst);
	destroyBST(pbst);
}
