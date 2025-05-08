#include <pthread.h> // pthread
#include <stdbool.h> // bool
#include <stdio.h>   // printf
#include <unistd.h>  // Sleep

#define BUFSIZE 10
#define REPS 5000
int gbb[BUFSIZE]; // bounded buffer
int gin = 0;      // in cursor
int gout = 0;     // out cursor
int negs = 0;     // # of -1s
pthread_mutex_t mutex;
pthread_mutex_t mutex1;

int totalConsumed = 0;

bool empty() { return gin == gout; }
bool full() { return (gin + 1) % BUFSIZE == gout; }
void lock() { pthread_mutex_lock(&mutex); }
void unlock() { pthread_mutex_unlock(&mutex); }

void lock1() { pthread_mutex_lock(&mutex1); }
void unlock1() { pthread_mutex_unlock(&mutex1); }
void insert(int x)
{
    while (full())
        usleep(1); // millisecs
    gbb[gin] = x;
    gin = (gin + 1) % BUFSIZE;
}
int extract()
{
    while (empty())
        usleep(1);
    int x = gbb[gout];
    gbb[gout] = -9;
    gout = (gout + 1) % BUFSIZE;
    return x;
}

void *produce(void *arg)
{
    pthread_t me = pthread_self();
    for (int i = 0; i < REPS; ++i)
    {
        lock();
        insert(i);
        printf("TID %d produced %d \n", me, i);
        unlock();
    }
    insert(-1);
    return NULL;
}
void *consume(void *arg)
{
    while (true)
    {
        int x = extract();
        if (x == -1)
            ++negs;
        lock1();
        printf("Consumed: %d\n", x);
        unlock1();
        ++totalConsumed;
        if (negs == 2)
            break;
    }
    printf("Total Consumed: %d\n", totalConsumed);
    return NULL;
}
int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t producer1, producer2, consumer;
    pthread_create(&producer1, NULL, produce, NULL);
    pthread_create(&producer2, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);
    pthread_join(producer1, NULL);
    pthread_join(producer2, NULL);
    pthread_join(consumer, NULL);
    printf("All done! \n");
    return 0;
}