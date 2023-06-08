#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_QUEUE_SIZE 20
#define MAX_NUM_SIZE 100

pthread_t p_thread[3];

typedef int element;
typedef struct
{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

QueueType queue;
pthread_mutex_t mutex;
pthread_mutex_t num_mutex;

void init_queue(QueueType *q);

int is_empty(QueueType *q);

int is_full(QueueType *q);

void queue_print(QueueType *q);

void enqueue(QueueType *q, element item);

element dequeue(QueueType *q);

void *input_func(void *arg);

void *output_func(void *arg);

void *input_num(void *arg);