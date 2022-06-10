#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "TreePrintLibrary.h"
#define TEST(newNode) do{if(newNode == NULL){printf("error");exit(1);}}while(0)


void initBST(BST* bst)
{
	bst->root = NULL;
}

void insertBST(BST* bst, int value)
{
	TreeNode* newNode = createNewNode(value);
	if (bst->root == NULL)//If its the first node created
	{
		bst->root = newNode;
		return 1;
	}
	else
		insertToCurrectPlace(bst->root, newNode);//Place the node in the currect place
}	

void insertToCurrectPlace(TreeNode* root, TreeNode* newNode)
{
	if (newNode->element <= root->element) //left subtree (<=)
		if (root->left == NULL)
			root->left = newNode;
		else
			insertToCurrectPlace(root->left, newNode);
	if (newNode->element > root->element) //right subtree (>)
		if (root->right == NULL)
			root->right = newNode;
		else
			insertToCurrectPlace(root->right, newNode);
}

TreeNode* createNewNode(int value)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	TEST(&newNode);
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->element = value;	
	return newNode;
}

void printTreeInorder(BST* bst)
{
	if (bst != NULL)
	{
		printTree(bst->root);
	}
	else
	{
		printf("Empty tree.\n");
	}
}

void printTree(TreeNode* root)
{
	if (root != NULL)
	{
		printTree(root->left);
		printf("%d,", root->element);
		printTree(root->right);
	}
}

void destroyBST(BST* bst)
{
	if (bst == NULL)
		return 0;
	if (bst->root != NULL)
		freeBinaryTree(bst->root);
	bst->root = NULL;
}

void freeBinaryTree(TreeNode* node)
{
	if (node != NULL) 
	{
		freeBinaryTree(node->right);
		freeBinaryTree(node->left);
		free(node);
	}
}

int findIndexNFromLast(BST* bst, int N)
{
	if (bst != NULL)
		return findIndexN(bst->root, N);
	else
		return -1;
}

int findIndexN(TreeNode* root, int N)
{
	if (root != NULL)
	{
		if (N == 0)
			return root->element;
		N = findIndexN(root->right, N) - 1;
		if (N == 0)
			return root->element;
		N = findIndexN(root->left, N - 1);
		return N;
	}
}

int sameHeightLeaves(BST* bst)
{
	int nMax = 0;
	getMaxHeight(bst->root, 0, &nMax);//First we check for the maximum height then we compare all height with that max
	if (compareHeights(bst->root, 0, nMax) == 0)
		return 1;
	else
		return 0;
	//return (!compareHeights(bst->root, 0, nMax)) ? 1 : 0;//Compare the heights and return 1 if all equal
}

int getMaxHeight(TreeNode* root,int n, int* nMax)
{
	if (root != NULL)
	{
		getMaxHeight(root->right, n + 1, nMax);
		getMaxHeight(root->left, n + 1, nMax);
		if (n > *nMax)
			*nMax = n;
	}
}

int compareHeights(TreeNode* root, int n, int nMax)
{
	if (root != NULL)
	{
		return compareHeights(root->right, n, nMax) + compareHeights(root->left, n, nMax);//Stack all awnsers and return them
		//If we got '1' at least one time, then we know the finale return will be bigger the 0
	}
	else
	{
		if (n - 1 != nMax)//Not same height as the max height
			return 1;
		else
			return 0;
	}
}