#include "queue.h"

int enqueue(Queue *queue, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // newNode 생성
    newNode->data = data;
    newNode->next = queue->front;
 
    if (isEmpty(queue))    // 큐가 비어있을 때
    {
        queue->front = newNode;
    }
    else if (isFull(queue))
    {
        return 11;
    }
    else    // 비어있지 않을 때
    {
        queue->rear->next = newNode;    //맨 뒤의 다음을 newNode로 설정
    }
    queue->rear = newNode;    //맨 뒤를 newNode로 설정 
    queue->count++;    //큐안의 노드 개수를 1 증가
    return (queue->count);
}