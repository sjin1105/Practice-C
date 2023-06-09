#include "main.h"

int main(void)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t p_thread[2];
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

    pthread_join(p_thread[0], (void **)&status);
    pthread_join(p_thread[1], (void **)&status);

    pthread_mutex_destroy(&mutex);

    return 0;
}