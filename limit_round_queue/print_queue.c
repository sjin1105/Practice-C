#include "queue.h"

void print_queue(Queue *queue)
{
    values num = {0,0};
    int data;
    Queue temp;
    temp = *queue;
    Node *pptr;
    if (isEmpty(queue))    //큐가 비었을 때
    {
        printf("Error : Queue is empty!\n");
        return;
    }
    while (!isEmpty(&temp))
    {
        pptr = temp.front;    //맨 앞의 노드 ptr 설정 
        data = pptr->data;    // return 할 데이터  
        temp.front = pptr->next;    //맨 앞은 ptr의 다음 노드로 설정
        // free(pptr);    // ptr 해제 
        printf("%d번째 데이터 %d\n", temp.count--, data);
    }

}