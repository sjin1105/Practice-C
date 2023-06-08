#include "main.h"

int main(void)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex_file, NULL);
    int thr_id;
    int status;
    int i;

    void *func_ary[3] = {*input_func, *output_func, *output_file};

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

    for (i = 0; i < 3; i++)
    {
        thr_id = pthread_create(&p_thread[i], NULL, func_ary[i], (void *)NULL);
        if (thr_id < 0)
        {
            perror("thread create error : ");
            exit(0);
        }
    }

    int a = 0;
    printf("1 out\n");
    scanf("%d", &a);
    if (a == 1)
    {
        for (i = 0; i < 3; i++)
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
