#include "main.h"

void *input_func(void *arg)
{
    int i = 0;
    while (1)
    {
        FILE *pfile = fopen("a.txt", "rb");
        char *pline;
        char line[100];
        while ((pline = fgets(line, 100, pfile)) != NULL)
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
    }
}

void *output_func(void *arg)
{
    int out_num;
    while (1)
    {
        while (is_empty(&queue))
        {
            // printf("queue is empty!\n");
        }
        pthread_mutex_lock(&mutex);
        out_num = dequeue(&queue);
        pthread_mutex_unlock(&mutex);

        while (is_full(&file_queue))
        {
            // printf("queue is full!\n");
        }
        pthread_mutex_lock(&mutex_file);
        enqueue(&file_queue, out_num);
        pthread_mutex_unlock(&mutex_file);
        // FILE* pfile = fopen("out.txt", "ab");
        // fprintf(pfile, "꺼내진 숫자 : %d\n", out_num);
        // fclose(pfile);
        // printf("꺼내진 숫자 : %d \n", out_num);
        // queue_print(&queue);
    }
}

void *output_file(void *arg)
{
    int out_file;
    while (1)
    {
        while (is_empty(&file_queue))
        {
            // printf("queue is empty!\n");
        }
        pthread_mutex_lock(&mutex_file);
        out_file = dequeue(&file_queue);
        pthread_mutex_unlock(&mutex_file);
        FILE *pfile = fopen("out.txt", "ab");
        fprintf(pfile, "꺼내진 숫자 : %d\n", out_file);
        fclose(pfile);
        // printf("꺼내진 숫자 : %d \n", out_num);
        // queue_print(&queue);
    }
}