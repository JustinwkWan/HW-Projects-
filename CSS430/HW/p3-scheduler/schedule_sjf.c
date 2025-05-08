#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "task.h"
#include "list.h"
#include "CPU.h"

static struct node *g_head = NULL;

void add(char *name, int priority, int burst) {
    Task *task = malloc(sizeof(Task));
    task->name = strdup(name);
    task->priority = priority;
    task->burst = burst;
    insert(&g_head, task);
}

bool comesBefore(int a, int b) {
    return a < b;
}

Task *pickNextTask() { 
    if(!g_head) {
        return NULL;
    }

    struct node *temp; 
    temp = g_head; 
    Task *best_sofar = temp->task;
    int smallest = INT_MAX;
    while(temp != NULL) {
        if(comesBefore(temp->task->burst, smallest)) {
            smallest = temp->task->burst;
            best_sofar = temp->task;
        }
        temp = temp->next;
    }
    delete (&g_head, best_sofar);
    return best_sofar;
}

void schedule() {
    Task *task;
    int currentTime = 0;

    while ((task = pickNextTask()) != NULL) {
        run(task, task->burst);
        currentTime += task->burst;
        printf("\tTime is now: %d\n", currentTime);
        free(task);
    }
}