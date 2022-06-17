#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* new(int val);
void push(struct node **head, int val);
void insert_after(struct node *prev, int val);
void append(struct node **head, int val);
void delete(struct node **head, int key);
void delete_r(struct node **head, int key);
void traverse(struct node *head);

int main()
{
	struct node *head = new(23);

	push(&head, 24);
	push(&head, 64);
	push(&head, 13);

	insert_after(head, 112);

	append(&head, 97);
	delete(&head, 64);
	delete_r(&head, 13);

	printf("traverse: ");
	traverse(head);

	free(head);

	return 0;
}

struct node* new(int val)
{
	struct node* tmp = (struct node*) malloc(sizeof(struct node));
	tmp->data = val;
	tmp->next = NULL;

	return tmp;
}

// insert a new node at the beginning
// Time complexity is O(1)
void push(struct node **head, int val)
{
	struct node *newNode = new(val);
	newNode->next = *head;
	*head = newNode;
}

// insert after a given node
// Time complexity is O(1)
void insert_after(struct node *prev, int val)
{
	if(prev == NULL)
	{
		return;
	}
	struct node *newNode = new(val);
	newNode->next = prev->next;
	prev->next = newNode;
}

// insert at the end of the list
// Time complexity is O(n)
void append(struct node **head, int val)
{
	if(*head == NULL)
	{
		*head = new(val);
		return;
	}
	struct node *newNode = new(val);
	struct node *tmp = *head;

	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = newNode;
}

// given a pointer to the head
// and a key, delete the first occurrence
// of the key in the list ITERATIVELY
void delete(struct node **head, int key)
{
	struct node *tmp = *head, *prev;
	if(tmp == NULL)
	{
		return;
	}

	if(tmp != NULL && tmp->data == key)
	{
		*head = tmp->next;
		free(tmp);
		return;
	}

	while(tmp != NULL && tmp->data != key)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	if(tmp == NULL)
	{
		return;
	}

	prev->next = tmp->next;
	free(tmp);
}

// delete recursively
void delete_r(struct node **head, int key)
{
	if(*head == NULL)
	{
		return;
	}
	if((*head)->data == key)
	{
		struct node *tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return;
	}
	delete_r(&(*head)->next, key);
}

void traverse(struct node *head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

