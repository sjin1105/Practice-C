#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 5

enum MENU_VALUE {	MENU_ADD=1,
					MENU_DELETE,
					MENU_SHOW,
					MENU_EXIT };

typedef int element;
typedef struct {  // 원형 큐 타입
	element data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
}
// 원형 큐 초기화
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
    memset(q->data, -1, sizeof(q->data));
}
// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return ( q->front == q->rear );
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형 큐 출력 함수
void queue_print(QueueType *q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    int i = q->front;
    for (int l = 0; l < MAX_QUEUE_SIZE; l++)
    {
        printf("%d | ", q->data[l]);
    }
    printf("\n");
}
// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q)) {
        error("큐가 포화상태입니다");
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[ q->rear ] = item;
    }
}
// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q)){
        error("큐가 공백상태입니다");
        return -1;
    }
	else{
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        element data = q->data[q->front];
        q->data[q->front] = -1;
        return data;
    }
}
// 메인
int main(void)
{
	QueueType queue;
	int element;
	init_queue(&queue);
	int choice_num;

    while( 1 )
	{
		printf("\n===================== MENU =====================\n");
		printf("1. ADD\n");
		printf("2. DELETE\n");
		printf("3. PRINT\n");
		printf("4. EXIT\n");

		printf("* Select Num. : ");
		scanf("%d", &choice_num);

		switch( choice_num )
		{
			case MENU_ADD:
                printf("정수를 입력. : ");
                scanf("%d", &element);
                enqueue(&queue, element);
                queue_print(&queue);
				break;

			case MENU_DELETE:
                element = dequeue(&queue);
                printf("꺼내진 정수: %d \n", element);
                queue_print(&queue);
				break;

			case MENU_SHOW:
            	queue_print(&queue);
				break;

			case MENU_EXIT:
				return 0;

			default:
				printf("\n* System : Invalid Num.\n");
				break;
		}
        if (is_full(&queue))
        {
            printf("큐는 포화상태\n");
        }
        if (is_empty(&queue))
        {
            printf("큐는 공백상태\n");
        }
    }
	return 0;
}