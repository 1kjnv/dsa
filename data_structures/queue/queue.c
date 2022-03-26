#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* items;
};

struct Queue* createQueue(unsigned capacity)
{
	struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
	q->capacity = capacity;
	q->front = q->size = 0;

	q->rear = capacity-1;
	q->items = (int*) malloc(sizeof(int) * q->capacity);

	return q;
}

int isFull(struct Queue* q)
{
	return (q->size == q->capacity);
}

int isEmpty(struct Queue* q)
{
	return (q->size == 0);
}

void enqueue(struct Queue* q, int val)
{
	if(isFull(q))
	{
		return;
	}
	q->rear = (q->rear + 1) % q->capacity;
	q->items[q->rear] = val;
	q->size += 1;
}

int dequeue(struct Queue* q)
{
	if(isEmpty(q))
	{
		return INT_MIN;
	}
	int item = q->items[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size -= 1;
	return item;
}

int front(struct Queue* q)
{
	if(isEmpty(q))
	{
		return INT_MIN;
	}
	return q->items[q->front];
}

int rear(struct Queue* q)
{
	if(isEmpty(q))
	{
		return INT_MIN;
	}
	return q->items[q->rear];
}

int main()
{
	struct Queue* q = createQueue(100);

	enqueue(q, 20);
	enqueue(q, 39);
	enqueue(q, 45);
	enqueue(q, 78);
	enqueue(q, 56);

	printf("Front: %d\n", front(q));
	printf("Rear: %d\n", rear(q));

	return 0;
}
