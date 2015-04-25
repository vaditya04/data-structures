#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
	struct BST *left;
	int data;
	struct BST *right; 
	struct BST *succ;
}BST;

BST* FindMin (BST* node);
BST* Insert ( BST* root, BST* node, int data);
BST* Delete(BST* root, BST* node, int data);
BST* FindInSuccessor(BST* root, BST* node);
BST* Find(BST* node, int data);

void PrintInOrder(BST* node);
#endif