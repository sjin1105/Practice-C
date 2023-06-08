#include "queue.h"

values dequeue(Queue *queue)
{
    values num = {0,0};
    int data;
    Node *ptr;
    if (isEmpty(queue))    //큐가 비었을 때
    {
        printf("Error : Queue is empty!\n");
        return num;
    }
    ptr = queue->front;    //맨 앞의 노드 ptr 설정 
    data = ptr->data;    // return 할 데이터  
    queue->front = ptr->next;    //맨 앞은 ptr의 다음 노드로 설정
    queue->rear->next = queue->front;
    free(ptr);    // ptr 해제 
    //queue->count--;    
    
    num.count = queue->count--;  //큐의 노드 개수를 1 감소
    num.data = data;
    return num;
}