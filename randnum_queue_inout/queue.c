#include "main.h"

void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
    memset(q->data, -1, sizeof(q->data));
}

int is_empty(QueueType *q)
{
	return ( q->front == q->rear );
}

int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q)
{
	printf("QUEUE(front=%-3d rear=%-3d) = ", q->front, q->rear);
    int i = q->front;
    for (int l = 0; l < MAX_QUEUE_SIZE; l++)
    {
        printf("%-3d | ", q->data[l]);
    }
    printf("\n");
}

void enqueue(QueueType *q, element item)
{
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[ q->rear ] = item;
}

element dequeue(QueueType *q)
{
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    element data = q->data[q->front];
    q->data[q->front] = -1;
    return data;
}