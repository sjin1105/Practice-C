#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int count; // 큐 안의 노드 개수
} Queue;

typedef struct value
{
    int count;
    int data;
} values;

void initQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;
    queue->count = 0; // 큐 안의 노드 개수를 0으로 설정
}

int isEmpty(Queue *queue)
{
    return queue->count == 0; // 큐안의 노드 개수가 0이면 빈 상태
}

int enqueue(Queue *queue, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // newNode 생성
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) // 큐가 비어있을 때
    {
        queue->front = newNode;
    }
    else // 비어있지 않을 때
    {
        queue->front->next = newNode; // 맨 뒤의 다음을 newNode로 설정
    }
    queue->front = newNode; // 맨 뒤를 newNode로 설정
    queue->count++;         // 큐안의 노드 개수를 1 증가
    return (queue->count);
}

values dequeue(Queue *queue)
{
    values num = {0, 0};
    int data;
    Node *ptr;
    if (isEmpty(queue)) // 큐가 비었을 때
    {
        printf("Error : Queue is empty!\n");
        return num;
    }
    ptr = queue->rear;       // 맨 앞의 노드 ptr 설정
    data = ptr->data;        // return 할 데이터
    queue->rear = ptr->next; // 맨 앞은 ptr의 다음 노드로 설정
    free(ptr);               // ptr 해제
    // queue->count--;

    num.count = queue->count--; // 큐의 노드 개수를 1 감소
    num.data = data;
    return num;
}

int main(void)
{
    int i;
    Queue queue;

    initQueue(&queue); // 큐 초기화
    for (i = 1; i <= 5; i++)
    {
        printf("%d번째 데이터 %d\n", enqueue(&queue, i), i);
    }
    printf("\n");
    for (i = 1; i <= 4; i++) // 큐가 빌 때까지
    {
        values re = dequeue(&queue);
        printf("%d번째 데이터 %d\n", re.count, re.data); // 큐에서 꺼내온 값 출력
    }
    printf("\n");
    for (i = 1; i <= 5; i++)
    {
        printf("%d번째 데이터 %d\n", enqueue(&queue, i), i);
    }
    printf("\n");
    while (!isEmpty(&queue)) // 큐가 빌 때까지
    {
        values re = dequeue(&queue);
        printf("%d번째 데이터 %d\n", re.count, re.data); // 큐에서 꺼내온 값 출력
    }
    printf("\n");
    return 0;
}