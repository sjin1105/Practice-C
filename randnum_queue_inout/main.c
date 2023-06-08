#include "main.h"

int main(void)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&num_mutex, NULL);

    int thr_id;
    int status;

    init_queue(&queue);

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

    thr_id = pthread_create(&p_thread[2], NULL, input_num, (void *)NULL);
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
    pthread_mutex_destroy(&num_mutex);

    return 0;
}