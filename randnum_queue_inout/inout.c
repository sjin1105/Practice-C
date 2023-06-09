#include "main.h"

void *input_num(void *arg)
{
    int i;
    while(1)
    {
        srand((unsigned int) time(NULL));
        i = rand() % 10;
        pthread_mutex_lock(&num_mutex);
        FILE* pfile = fopen("a.txt", "ab");

        fprintf(pfile, "%d\n", i);

        fclose(pfile);
        pthread_mutex_unlock(&num_mutex);
    }
}

void *input_func(void *arg)
{
    int i = 0;
    while (1)
    {
        pthread_mutex_lock(&num_mutex);
        FILE* pfile = fopen("a.txt", "rb");
        char *pline;
        char line[100];
        while((pline = fgets(line, 100, pfile)) != NULL)
        {
            int ai;
            ai = atoi(pline);
            while (is_full(&queue))
            {
                // printf("queue is full!\n");
            }
            pthread_mutex_lock(&mutex);
            enqueue(&queue, ai);
            pthread_mutex_unlock(&mutex);
            // printf("넣어진 숫자 : %d \n", ai);
            // queue_print(&queue);
        }
        fclose(pfile);
        FILE* ffile = fopen("a.txt", "wb");
        fclose(ffile);
        pthread_mutex_unlock(&num_mutex);
    }
}

void *output_func(void *arg)
{
    int out_num;
    while(1)
    {
        while (is_empty(&queue))
        {
            // printf("queue is empty!\n");
        }
        pthread_mutex_lock(&mutex);
        out_num = dequeue(&queue);
        pthread_mutex_unlock(&mutex);
        FILE* pfile = fopen("out.txt", "ab");
        fprintf(pfile, "꺼내진 숫자 : %d\n", out_num);
        fclose(pfile);
        // printf("꺼내진 숫자 : %d \n", out_num);
        // queue_print(&queue);
    }
}