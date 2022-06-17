#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev, *next;
};

struct node* new(int val);
void push(struct node **head, int val);
void insert_after(struct node **prev, int val);
void append(struct node **head, int val);
void traverse(struct node *head);

int main()
{
	struct node *head = new(3);
	struct node *second = new(35);
	struct node *third = new(53);
	struct node *fourth = new(857);

	head->next = second;
	second->next = third;
	second->prev = head;
	third->next = fourth;
	third->prev = second;
	fourth->prev = third;

	push(&head, 1);
	insert_after(&second, 65);
	append(&fourth, 988);

	printf("traverse: ");
	traverse(head);

	return 0;
}

struct node* new(int val)
{
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = val;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
};

// insert at the beginning
void push(struct node **head, int val)
{
	if(*head == NULL)
	{
		*head = new(val);
		return;
	}

	struct node *tmp = new(val);
	tmp->next = *head;
	*head = tmp;
}

// insert after a given node
void insert_after(struct node **prev, int val)
{
	if(prev == NULL)
	{
		return;
	}
	struct node *tmp = new(val);
	tmp->next = (*prev)->next;
	tmp->prev = *prev;
	(*prev)->next = tmp;
	if(tmp->next != NULL)
	{
		tmp->next->prev = tmp;
	}
}

// append at the end
void append(struct node **head, int val)
{
	struct node *tmp = *head;
	struct node *newNode = new(val);
	if(*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
		return;
	}
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->prev = tmp;
}

// traverse
void traverse(struct node *head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
