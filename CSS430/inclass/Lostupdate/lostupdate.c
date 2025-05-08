#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// LostUpdates.c
// Build:  gcc -std=c11 -l pthread  lostupdates.c
// Run:    a.exe   (Windows);
//         ./a.out (Linux)
int gcount = 0;
void *bump(void *arg)
{
    for (int i = 1; i <= 50000; ++i)
    {
        // if (i % 100 == 0)
        //     usleep(100);
        ++gcount;
    }
    return NULL;
}
int main()
{
    pthread_t bumper1, bumper2, bumper3;
    pthread_create(&bumper1, NULL, bump, NULL);
    pthread_create(&bumper2, NULL, bump, NULL);
    pthread_create(&bumper3, NULL, bump, NULL);
    pthread_join(bumper1, NULL);
    pthread_join(bumper2, NULL);
    pthread_join(bumper3, NULL);
    printf("Final value of gcount = %d \n", gcount);
    return 0;
}