#include <stdio.h>
#include <pthread.h>
int g_tally = 0;
pthread_mutex_t g_mutex;
void *counter(void *arg)
{
    for (int i = 1; i <= 50000; ++i)
    {
        pthread_mutex_lock(&g_mutex);
        ++g_tally;
        pthread_mutex_unlock(&g_mutex);

        pthread_t tid = pthread_self();
        printf("tid = %d, i = %d \n", tid, g_tally);
    }
    return NULL;
}
int main()
{
    pthread_mutex_init(&g_mutex, NULL);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, counter, NULL);
    pthread_create(&t2, NULL, counter, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}