#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int cnt = 0;

struct stack
{
	int items[SIZE];
	int top;
};
typedef struct stack st;

void createEmptyStack(st *s)
{
	s->top = -1;
}

// check if the stack is full
int isFull(st *s)
{
	if(s->top == SIZE-1)
	{
		return 1;
	}
	return 0;
}

// check if the stack is empty
int isEmpty(st *s)
{
	if(s->top == -1)
	{
		return 1;
	}
	return 0;
}

// push into the stack
void push(st *s, int val)
{
	if(isFull(s))
	{
		printf("The Stack is Full!\n");
		return;
	}
	s->top++;
	s->items[s->top] = val;
	cnt++;
}

// pop an element from the stack
int pop(st *s)
{
	if(isEmpty(s))
	{
		printf("The Stack is Empty!\n");
		return -1;
	}
	cnt--;
	return s->items[s->top--];
}

// print stack items
void printStacK(st *s)
{
	if(isEmpty(s))
	{
		printf("The stack is empty!\n");
		return;
	}
	for(int i = 0; i < cnt; i++)
	{
		printf("%d ", s->items[i]);
	}
	printf("\n");
}

int main()
{
	st *s = (st *) malloc(sizeof(st));

	createEmptyStack(s);

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);

	printStacK(s);

	pop(s);

	printStacK(s);

	return 0;
}
