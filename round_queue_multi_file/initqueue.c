#include "queue.h"

void initQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;
    queue->count = 0;    // 큐 안의 노드 개수를 0으로 설정
}