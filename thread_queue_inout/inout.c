#include "main.h"

void *input_func(void *arg)
{
    int i = 0;
    while (i != MAX_NUM_SIZE)
    {
        while (is_full(&queue))
        {
            printf("queue is full!\n");
            sleep(0.1);
        }
        pthread_mutex_lock(&mutex);
        enqueue(&queue, i);
        printf("넣어진 숫자 : %d \n", i);
        queue_print(&queue);
        pthread_mutex_unlock(&mutex);
        i++;
    }
}

void *output_func(void *arg)
{
    int i = 0;
    int out_num;
    while(i != MAX_NUM_SIZE)
    {
        while (is_empty(&queue))
        {
            printf("queue is empty!\n");
            sleep(0.1);
        }
        pthread_mutex_lock(&mutex);
        out_num = dequeue(&queue);
        printf("꺼내진 숫자 : %d \n", out_num);
        queue_print(&queue);
        pthread_mutex_unlock(&mutex);
        i++;
    }

}
