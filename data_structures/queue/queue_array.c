#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// queue implementation using arrays
struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* items;
};

struct Queue* create_queue(unsigned capacity);
int is_full(struct Queue *q);
int is_empty(struct Queue *q);
void enqueue(struct Queue *q, int val);
int dequeue(struct Queue *q);
int front(struct Queue *q);
int rear(struct Queue *q);

int main()
{
	struct Queue* q = create_queue(100);

	enqueue(q, 20);
	enqueue(q, 39);
	enqueue(q, 45);
	enqueue(q, 78);
	enqueue(q, 56);

	printf("Front: %d\n", front(q));
	printf("Rear: %d\n", rear(q));

	return 0;
}

struct Queue* create_queue(unsigned capacity)
{
	struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
	q->capacity = capacity;
	q->front = q->size = 0;

	q->rear = capacity-1;
	q->items = (int*) malloc(sizeof(int) * q->capacity);

	return q;
}

int is_full(struct Queue* q)
{
	return (q->size == q->capacity);
}

int is_empty(struct Queue* q)
{
	return (q->size == 0);
}

void enqueue(struct Queue* q, int val)
{
	if(is_full(q))
	{
		return;
	}
	q->rear = (q->rear + 1) % q->capacity;
	q->items[q->rear] = val;
	q->size += 1;
}

int dequeue(struct Queue* q)
{
	if(is_empty(q))
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
	if(is_empty(q))
	{
		return INT_MIN;
	}
	return q->items[q->front];
}

int rear(struct Queue* q)
{
	if(is_empty(q))
	{
		return INT_MIN;
	}
	return q->items[q->rear];
}

