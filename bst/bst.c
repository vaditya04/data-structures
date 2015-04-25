#include "bst.h"

BST* FindMin ( BST* node)
{
	if (node == NULL)
		return NULL;
	if (node->left)
	{
		return FindMin(node->left);
	}
	else
		return node;


}

BST* Insert ( BST* root, BST* node, int data)
{
	if (node == NULL)
	{
		BST* temp;
		temp = (BST *) malloc (sizeof(BST));
		temp->data = data;
		temp->left = temp->right = NULL;
		temp->succ = FindInSuccessor(root, temp);

		return temp;
	}

	if (data > node->data)
	{
		node->right = Insert(root, node->right, data);
	}
	else
	{
		node->left = Insert(root, node->left, data);
	}
	node->succ = FindInSuccessor(root, node);
	return node;
}

BST* Delete(BST* root, BST* node, int data)
{
    // base case
    if (node == NULL) 
    	return node;
 
    // If the data to be deleted is smaller than the node's data,
    // then it lies in left subtree
    if (data < node->data)
        node->left = Delete(root, node->left, data);
 
    // If the data to be deleted is greater than the node's data,
    // then it lies in right subtree
    else if (data > node->data)
        node->right = Delete(root, node->right, data);
 
    // if data is same as node's data, then This is the node
    // to be deleted
	else
    {
        // node with only one child or no child
        if (node->left == NULL)
        {
            BST* temp = node->right;
            free(node);
            if (temp != NULL)
	            temp->succ = FindInSuccessor(root, temp);
            return temp;
        }
        else if (node->right == NULL)
        {
            BST* temp = node->left;
            free(node);
    		if (temp != NULL)
	            temp->succ = FindInSuccessor(root, temp);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
       BST* temp = FindMin(node->right);
 
        // Copy the inorder successor's content to this node
        node->data = temp->data;
 
        // Delete the inorder successor
        node->right = Delete(root, node->right, temp->data);
    }
    node->succ = FindInSuccessor(root, node);
    return node;
}

BST* FindInSuccessor(BST* root, BST* node)
{
    // step 1 of the above algorithm
    if( node->right != NULL )
        return FindMin(node->right);
 
    BST* succ = NULL;
 
    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (node->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (node->data > root->data)
            root = root->right;
        else
           break;
    }
 
    return succ;
}

BST* Find(BST* node, int data)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (data > node->data)
	{
		return Find(node->right, data);
	}
	else if ( data < node->data)
	{
		return Find(node->left, data);
	}
	else
		return node;
}

void PrintInOrder (BST* node)
{
        node = FindMin(node);

        while (node != NULL)
        {
        	printf("%d\n", node->data);
        	node = node->succ;
        }
}