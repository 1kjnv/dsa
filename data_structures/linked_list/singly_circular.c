#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* new(int val);
void push(struct node **head, int val);;
void traverse(struct node *n);

int main()
{
	struct node *head = new(1);

	push(&head, 23);
	push(&head, 56);
	push(&head, 67);

	printf("traversal: ");
	traverse(head);

	free(head);

	return 0;
}

struct node* new(int val)
{
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = newNode;

	return newNode;
}

// push at the beginning
void push(struct node **head, int val)
{
	struct node *prev = *head;
	struct node *tmp = new(val);
	tmp->next = *head;

	if(*head != NULL)
	{
		while(prev->next != *head)
		{
			prev = prev->next;
		}
		prev->next = tmp;
	}
	else
	{
		tmp->next = tmp;
	}
	*head = tmp;
}

// traverse forward
void traverse(struct node *n)
{
	struct node *tmp = n;
	if(n != NULL)
	{
		do {
			printf("%d ", tmp->data);
			tmp = tmp->next;
		} while(tmp != n);
	}
	printf("\n");
}

