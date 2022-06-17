#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node* new(int val);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);

int main()
{
	struct node *root = new(1);
	root->left = new(2);
	root->right = new(54);

	printf("Preorder: ");
	preorder(root);
	printf("\n");

	printf("Inorder: ");
	inorder(root);
	printf("\n");

	printf("Postorder: ");
	postorder(root);
	printf("\n");

	return 0;
}

struct node* new(int val)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// preorder traversal
void preorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

// inorder traversal
void inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

// postorder traversal
void postorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

