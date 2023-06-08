#include "queue.h"

int main(void)
{
    int i;
    Queue queue;
    int choice_num = 0;
    int num_data = 0;
    initQueue(&queue);//큐 초기화

    while (1)
    {

       	printf("\n===================== MENU =====================\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
        printf("3. Print queue\n");
		printf("4. EXIT\n");

        printf("* Select Num. : ");
		scanf("%d", &choice_num);
		fflush(stdin);
        values re;
        switch( choice_num )
		{
			case MENU_EN:
                printf("* Input Data. : ");
				scanf("%d", &num_data);
                fflush(stdin);
                int num_queue = enqueue(&queue, num_data);
                if (num_queue == 11)
                {
                    printf("* queue is full *");
                }
                else{
                    printf("%d번째 데이터 %d\n", num_queue, num_data);
                }
				break;

			case MENU_DE:
				re = dequeue(&queue);
                printf("%d번째 데이터 %d\n", re.count, re.data);
				break;

            case MENU_PRINT:
                print_queue(&queue);
                break;

			case MENU_EXIT:
				while (!isEmpty(&queue))    // 큐가 빌 때까지 
                {
                    values re = dequeue(&queue);
                    printf("%d번째 데이터 %d\n", re.count, re.data);    //큐에서 꺼내온 값 출력
                }
				return 0;

			default:
				printf("\n* System : Invalid Num.\n");
				break;
		}
    }
    return 0;
}