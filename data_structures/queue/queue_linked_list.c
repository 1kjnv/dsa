#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front, *rear;
};

struct node* new(int val)
{
    struct node *tmp = (struct node*) malloc(sizeof(struct node));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}

struct queue* create_q()
{
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue* q, int val)
{
    struct node *tmp = new(val);
    if(q->rear == NULL)
    {
        q->front = q->rear = tmp;
        return;
    }

    q->rear->next = tmp;
    q->rear = tmp;
}

void dequeue(struct queue* q)
{
    if(q->front == NULL)
    {
        return;
    }

    struct node *tmp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
    {
        q->rear = NULL;
    }
    free(tmp);
}

int main()
{
    struct queue *q = create_q();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    dequeue(q);

    printf("Front: %d\n", q->front->data);
    printf("Rear: %d\n", q->rear->data);

    return 0;
}
