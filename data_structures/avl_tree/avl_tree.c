#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
	int height;
};

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Calculate height
int height(struct node *n)
{
	if(n == NULL)
	{
		return 0;
	}
	return n->height;
}

// Create a new node
struct node *create(int key)
{
	struct node *n = (struct node *) malloc(sizeof(struct node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	n->height = 1;
	
	return n;
}

// Right rotate
struct node *right_rotate(struct node *y)
{
	struct node *x = y->left;
	struct node *t2 = x->right;

	x->right = y;
	y->left = t2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	
	return x;
}

// Left rotate
struct node *left_rotate(struct node *x)
{
	struct node *y = x->right;
	struct node *t2 = y->left;

	y->left = x;
	x->right = t2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

// Get the balance factor
int get_balance(struct node *n)
{
	if(n == NULL)
	{
		return 0;
	}
	return height(n->left) - height(n->right);
}

// Insert a new node
struct node *insert(struct node *n, int key)
{
	// if the tree is empty
	if(n == NULL)
	{
		return (create(key));
	}

	// if the key to be inserted is less than the key of the root, perform insert operation in the left subtree, recursively
	if(key < n->key)
	{
		n->left = insert(n->left, key);
	}

	// if the key to be inserted is bigger than the key of the root, perform insert operation in the right subtree, recursively
	else if(key > n->key)
	{
		n->right = insert(n->right, key);
	}

	// if the key is equal to the key of the root node, just return the node
	else
	{
		return n;
	}

	// update the balance factor of each node and balance the tree
	n->height = 1 + max(height(n->left), height(n->right));
	int balance = get_balance(n);

	// if the balance is bigger than 1 and the key is less than the key of left subtree, perform right rotation
	if(balance > 1 && key < n->left->key)
	{
		return right_rotate(n);
	}

	// if the balance is less than -1 and the key is bigger than the key of the right subtree, perform left rotation
	if(balance < -1 && key > n->right->key)
	{
		return left_rotate(n);
	}

	// if the balance is greater than 1 but the key is bigger than the key of the left subtree then first do left rotate on left subtree
	// then perform right rotate on the node
	if(balance > 1 && key > n->left->key)
	{
		n->left = left_rotate(n->left);
		return right_rotate(n);
	}

	// if the balance is less than -1 but the key is less than the key of the right subtree then first perform right rotation on the right subtree
	// then perform left rotation on the node
	if(balance < -1 && key < n->right->key)
	{
		n->right = right_rotate(n->right);
		return left_rotate(n);
	}

	return n;
}

struct node *min_value_node(struct node *n)
{
	struct node *curr = n;
	
	while(curr->left != NULL)
	{
		curr = curr->left;
	}

	return curr;
}

// Delete a node from the tree
struct node *delete(struct node *root, int key)
{
	// If the tree is empty
	if(root == NULL)
	{
		return root;
	}

	// if the key is less than the key of the root, perform delete operation on the left subtree, recursively.
	if(key < root->key)
	{
		delete(root->left, key);
	}

	// if the key is greater than the key of the root then perform the delete operation on the right subtree, recursively.
	else if(key > root->key)
	{
		delete(root->right, key);
	}

	else
	{
		// when the root has only one child
		if((root->left == NULL) || (root->right == NULL))
		{
			struct node *tmp = root->left ? root->left : root->right;

			if(tmp == NULL)
			{
				tmp = root;
				root = NULL;
			}
			else
			{
				*root = *tmp;
			}
			free(tmp);
		}
		else
		{
			struct node *tmp = min_value_node(root->right);
			root->key = tmp->key;
			root->right = delete(root->right, tmp->key);
		}
	}

	if(root == NULL)
	{
		return root;
	}

	// update the balance factor of each node and the balance the tree
	root->height = 1 + max(height(root->left), height(root->right));
	int balance = get_balance(root);
	
	if(balance > 1 && get_balance(root->left) >= 0)
	{
		return right_rotate(root);
	}

	if(balance > 1 && get_balance(root->left) < 0)
	{
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}

	if(balance < -1 && get_balance(root->right) <= 0)
	{
		return left_rotate(root);
	}

	if(balance < -1 && get_balance(root->right) > 0)
	{
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}

// preorder traversal
void preorder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

// inorder traversal
void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

int main(void)
{
	struct node *root = NULL;

	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 7);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 8);

	printf("Inorder traversal: ");
	inorder(root);

	root = delete(root, 3);
	printf("\nAfter deletion: ");
	inorder(root);

	return 0;
}
