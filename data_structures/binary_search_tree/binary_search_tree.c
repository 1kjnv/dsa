#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

// Create a node
struct node* create(int item)
{
	struct node* tmp = (struct node*) malloc(sizeof(struct node));
	tmp->key = item;
	tmp->left = tmp->right = NULL;
	return tmp;
}

// Inorder Traversal
void inorder(struct node* root)
{
	if(root != NULL)
	{
		// Traverse the left side
		inorder(root->left);

		printf("%d -> ", root->key);

		// Traverse the right side
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key)
{
	// Return a new node if the tree is empty
	if(node == NULL)
	{
		return create(key);
	}

	// Traverse and find the right position for the key
	if(key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else
	{
		node->right = insert(node->right, key);
	}

	return node;
}

// Find the inorder successor
struct node* min_value(struct node* node)
{
	struct node* current = node;

	// Find the leftmost leaf
	while(current && current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

// Deleting a node
struct node* delete(struct node* root, int key)
{
	// If the tree is empty
	if(root == NULL)
	{
		return root;
	}

	// Find the node to be deleted
	if(key < root->key)
	{
		root->left = delete(root->left, key);
	}
	else if(key > root->key)
	{
		root->right = delete(root->right, key);
	}
	else
	{
		// If the node has only 1 child or no child
		if(root->left == NULL)
		{
			struct node* tmp = root->right;
			free(root);
			return tmp;
		}
		else if(root->right == NULL)
		{
			struct node* tmp = root->left;
			free(root);
			return tmp;
		}

		// If the node has 2 children
		struct node* tmp = min_value(root->right);

		// Place the inorder successor in position of the node to be deleted
		root->key = tmp->key;

		// Delete the inorder successor
		root->right = delete(root->right, tmp->key);
	}
	return root;
}

int main(void)
{
	struct node* root = NULL;

	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 4);

	printf("Inorder traversal: ");
	inorder(root);

	root = delete(root, 10);

	printf("\nAfter deleting 10: ");
	inorder(root);

	return 0;
}
