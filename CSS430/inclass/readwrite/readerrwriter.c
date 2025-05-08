#ifdef _WIN32
#include <windows.h> // Sleep
#endif

#ifdef linux
#include <unistd.h>
#endif

#include <pthread.h>   // pthread*
#include <semaphore.h> // sem*
#include <stdbool.h>   // true/false
#include <stdio.h>     // printf

#define NUMREADERS 4
#define NUMWRITERS 2
#define NUMREPS 10
#define NAP 1

int gData = 0;  // data in 'database'
int gReads = 0; // # current readers

pthread_mutex_t gReadMut = PTHREAD_MUTEX_INITIALIZER;
sem_t gReadSem, gWriteSem;

// ==================================================================
// Read from the database.  Multiple readers are allowed access to
// the database at the same time.  But only if there are no writers
// accessing it.  We bump the number of concurrent readers (gReads)
// under gReadMut.  If we are the first reader to be admitted, then
// prevent any writer from gaining access, via the gWriteSem
// ==================================================================
void *reader(void *arg)
{
    pthread_t me = pthread_self();
    for (int reps = 1; reps < NUMREPS; ++reps)
    {
        sleep(NAP);
        // before GOOD
        sem_wait(&gReadSem);
        pthread_mutex_lock(&gReadMut);

        // // after DEADLOCK
        // pthread_mutex_lock(&gReadMut);
        // sem_wait(&gReadSem);

        ++gReads;
        if (gReads == 1)
            sem_wait(&gWriteSem); // prevent writers
        pthread_mutex_unlock(&gReadMut);

        int value = gData;
        printf("<-- Reader %d is reading %d, currently %d readers\n", me, value, gReads);
        sleep(NAP);
        pthread_mutex_lock(&gReadMut);
        --gReads;
        printf("<-- Reader %d finished reading %d, currently %d readers\n", me,
               value, gReads);
        if (gReads <= 0)
            sem_post(&gWriteSem);
        pthread_mutex_unlock(&gReadMut);

        sem_post(&gReadSem);
    }
    return NULL;
}

// ==================================================================
// Write to the database NUMREPS times.  Only allowed for one writer
// at a time, by grabbing gWriteSem
// ==================================================================
void *writer(void *arg)
{
    pthread_t me = pthread_self();
    for (int reps = 1; reps < NUMREPS; ++reps)
    {
        sleep(NAP);
        sem_wait(&gWriteSem);
        int value = ++gData;
        printf("--> Writer %d has database lock, writing %d\n", me, value);
        sleep(NAP);
        sem_post(&gWriteSem);
    }
    return NULL;
}

// ==================================================================
// Spin up NUMWRITERS writer threads, and NUMREADERS reader threads
// ==================================================================
int main()
{
    pthread_t readerTids[NUMREADERS];
    pthread_t writerTids[NUMWRITERS];

    // change number of readers allowed from 3 to 10
    // when the number of readers is limited and there are many readers,
    // the writers rarely get a chance to enter critical section
    sem_init(&gReadSem, 0, 3);
    sem_init(&gWriteSem, 0, 1);

    for (int w = 0; w < NUMWRITERS; ++w)
    {
        pthread_create(&writerTids[w], NULL, writer, NULL);
    }

    for (int r = 0; r < NUMREADERS; ++r)
    {
        pthread_create(&readerTids[r], NULL, reader, NULL);
    }

    for (int w = 0; w < NUMWRITERS; ++w)
        pthread_join(writerTids[w], NULL);
    for (int r = 0; r < NUMREADERS; ++r)
        pthread_join(readerTids[r], NULL);

    return 0;
}