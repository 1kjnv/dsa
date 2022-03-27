#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
	int* items;
	int top;
	unsigned capacity;
};

struct stack* create(unsigned capacity)
{
	struct stack* s = (struct stack*) malloc(sizeof(struct stack));
	s->capacity = capacity;
	s->top = -1;
	s->items = (int*) malloc(sizeof(int) * s->capacity);

	return s;
}

int isFull(struct stack* s)
{
	return (s->top == s->capacity - 1);
}

int isEmpty(struct stack* s)
{
	return (s->top == -1);
}

void push(struct stack* s, int val)
{
	if(isFull(s))
	{
		return;
	}
	s->items[++s->top] = val;
}

int pop(struct stack* s)
{
	if(isEmpty(s))
	{
		return INT_MIN;
	}
	return s->items[s->top--];
}

int peek(struct stack* s)
{
	if(isEmpty(s))
	{
		return INT_MIN;
	}
	return s->items[s->top];
}

void printStack(struct stack* s)
{
	if(isEmpty(s))
	{
		printf("EMPTY STACK!\n");
		return;
	}
	for(int i = 0; i <= s->top; i++)
	{
		printf("%d ", s->items[i]);
	}
	printf("\n");
}

int main()
{
	struct stack* s = create(20);
	
	push(s, 10);
	push(s, 20);
	push(s, 30);

	printStack(s);

	pop(s);
	printStack(s);

	printf("\nPeek: %d\n", peek(s));

	return 0;
}
