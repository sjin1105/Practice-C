#include "main.h"

int main(void)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex_file, NULL);
    int thr_id;
    int status;

    init_queue(&queue);
    init_queue(&file_queue);

    int q_num = 0;
    FILE *qfile = fopen("a.txt", "wb");
    while (q_num != 101)
    {
        fprintf(qfile, "%d\n", q_num);
        q_num++;
    }
    fclose(qfile);

    thr_id = pthread_create(&p_thread[0], NULL, input_func, (void *)NULL);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }

    thr_id = pthread_create(&p_thread[1], NULL, output_func, (void *)NULL);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }

    thr_id = pthread_create(&p_thread[2], NULL, output_file, (void *)NULL);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }

    int a = 0;
    printf("1 out\n");
    scanf("%d", &a);
    if (a == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            pthread_cancel(p_thread[i]);
        }
    }

    // pthread_join(p_thread[0], (void **)&status);
    // pthread_join(p_thread[1], (void **)&status);
    // pthread_join(p_thread[2], (void **)&status);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&mutex_file);

    return 0;
}