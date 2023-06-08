#include "queue.h"

int isFull(Queue *queue)
{
    return queue->count == MAX_QUEUE;
}