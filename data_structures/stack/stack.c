#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
	int* items;
	int top;
	unsigned capacity;
};

struct stack* create(unsigned capacity);
int is_full(struct stack *s);
int is_empty(struct stack *s);
void push(struct stack *s, int val);
int pop(struct stack *s);
int peek(struct stack *s);
void print_stack(struct stack *s);

int main()
{
	struct stack* s = create(20);
	
	push(s, 10);
	push(s, 20);
	push(s, 30);

	print_stack(s);

	pop(s);
	print_stack(s);

	printf("\nPeek: %d\n", peek(s));

	return 0;
}

struct stack* create(unsigned capacity)
{
	struct stack* s = (struct stack*) malloc(sizeof(struct stack));
	s->capacity = capacity;
	s->top = -1;
	s->items = (int*) malloc(sizeof(int) * s->capacity);

	return s;
}

int is_full(struct stack* s)
{
	return (s->top == s->capacity - 1);
}

int is_empty(struct stack* s)
{
	return (s->top == -1);
}

void push(struct stack* s, int val)
{
	if(is_full(s))
	{
		return;
	}
	s->items[++s->top] = val;
}

int pop(struct stack* s)
{
	if(is_empty(s))
	{
		return INT_MIN;
	}
	return s->items[s->top--];
}

int peek(struct stack* s)
{
	if(is_empty(s))
	{
		return INT_MIN;
	}
	return s->items[s->top];
}

void print_stack(struct stack* s)
{
	if(is_empty(s))
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

