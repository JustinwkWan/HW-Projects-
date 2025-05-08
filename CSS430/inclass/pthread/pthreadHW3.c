#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // for fork()
#include <sys/types.h>  // for pid_t
#include <sys/wait.h>   // for wait()

int value = 0; 
void *runner(void *param); // the thread runner

int main(int argc, char *argv[]) {
    pid_t pid;
    pthread_t tid;       // thread ID
    pthread_attr_t attr; // thread attributes

    pid = fork();

    if (pid == 0) { // Child process
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("Child: value: %d\n", value);
    } else if (pid > 0) { // Parent process
        wait(NULL);
        printf("Parent: value: %d\n", value);
    } else {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}

void *runner(void *param) {
    value = 5; 
    pthread_exit(NULL);
}
