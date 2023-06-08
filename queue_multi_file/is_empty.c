#include "queue.h"

int isEmpty(Queue *queue)
{
    return queue->count == 0;    // 큐안의 노드 개수가 0이면 빈 상태
}