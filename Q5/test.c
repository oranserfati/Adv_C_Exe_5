#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"BST.h"
//#define TEST(newNode) do{if (newNode == NULL){printf("error");exit(1);}}while(0)

void initBST(BST* bst)
{
	bst->root = NULL;
}

TreeNode* createNode(int value)  //creating new tree node
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	TEST(&newNode);
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->element = value;
	return newNode;
}


void insertBST(BST* bst, int value) {
	TreeNode* newNode = createNode(value);
	if (bst->root == NULL)
		bst->root = newNode;//newNode becomes root for the entire tree
	else
		insertreeNode(bst->root, newNode); //start with the root of the tree and send newNode to its place in the tree 

}


//send a newNode to its place in the tree (left if element is smaller than root->element or right if larger)
void insertreeNode(TreeNode* root, TreeNode* newNode) {
	if (newNode->element <= root->element)
		if (root->left == NULL)
			root->left = newNode;
		else
			insertreeNode(root->left, newNode);

	if (newNode->element > root->element) { //right subtree (>)
		if (root->right == NULL)
			root->right = newNode;
		else
			insertreeNode(root->right, newNode);
	}
}

void printTreeInorder(BST* bst)
{
	if (bst->root != NULL)
	{
		printTreeNodeInorder(bst->root);
	}
	else
	{
		printf("The tree is empty\n");
	}
}

void printTreeNodeInorder(TreeNode* root) {
	if (root != NULL)
	{
		printTreeNodeInorder(root->left);
		printf("%d,", root->element);
		printTreeNodeInorder(root->right);
	}
}

void freeBinary(TreeNode* node)
{
	if (node != NULL)
	{
		freeBinary(node->right);
		freeBinary(node->left);
		free(node);
	}
}

void destroyBST(BST* bst)
{
	if (bst->root == NULL)
		return;

	else
		freeBinary(bst->root);
}

int findIndex(TreeNode* root, int N) {
	if (root == NULL) {
		return 0;
	}
	int rcount = 1 + findIndex(root->right, N);
	if (N == rcount)
		return root->element;
	int lcount = 1 + findIndex(root->left, N);
}

int findIndexNFromLast(BST* bst, int N) {
	int index = findIndex(bst->root, N);
	return index;
}

int sameHeightLeaves(BST* bst) {
	int num = sameHeight(bst->root);
	return num;
}

int sameHeight(TreeNode* root) {
	if (root == NULL)
		return 0;
	int left = 1 + sameHeight(root->left);
	int right = 1 + sameHeight(root->right);
	if (left != right) {
		return 0;
	}
	else

		return 1;
}