#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Lexicographical comparison
bool comesBefore(char *a, char *b) {
    return strcmp(a, b) < 0;
}

bool comesBefore(char *a, char *b) { return strcmp(a, b) < 0; }

// based on traverse from list.c
// finds the task whose name comes first in dictionary
Task *pickNextTask() {
  // if list is empty, nothing to do
  if (!g_head)
    return NULL;

  struct node *temp;
  temp = g_head;
  Task *best_sofar = temp->task;

  while (temp != NULL) {
    if (comesBefore(temp->task->name, best_sofar->name))
      best_sofar = temp->task;
    temp = temp->next;
  }
  // delete the node from list, Task will get deleted later
  delete (&g_head, best_sofar);
  return best_sofar;
}


// FCFS schedule
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
