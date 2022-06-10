#ifndef _BST_ADT_H
#define _BST_ADT_H

#include <stdio.h>

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;

void initBST(BST* bst);
void insertBST(BST* bst, int value);
void printTreeInorder(BST* bst);
void destroyBST(BST* bst);
int findIndexNFromLast(BST* bst, int N);
int sameHeightLeaves(BST* bst);
TreeNode* createNewNode(int value);
void insertToCurrectPlace(TreeNode* root, TreeNode* newNode);
void printTree(TreeNode* root);
int findIndexN(TreeNode* root, int N);
void freeBinaryTree(TreeNode* node);
int getMaxHeight(TreeNode* root, int n, int* nMax);
int compareHeights(TreeNode* root, int n, int nMax);

#endif // !_BST_ADT_H