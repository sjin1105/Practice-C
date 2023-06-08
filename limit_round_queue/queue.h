#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 10

typedef struct Node 
{
    int data;
    struct Node *next;
}Node;

typedef struct Queue 
{
    Node *front;
    Node *rear;
    int count; // 큐 안의 노드 개수  
}Queue;

typedef struct value
{
    int count;
    int data;
}values;

enum MENU_VALUE {	MENU_EN=1,
					MENU_DE,
                    MENU_PRINT,
					MENU_EXIT };

values dequeue(Queue *queue);

int isEmpty(Queue *queue);

int isFull(Queue *queue);

int enqueue(Queue *queue, int data);

void initQueue(Queue *queue);

void print_queue(Queue *queue);