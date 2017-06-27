#include "Queue.h"
#include <stdio.h>

void initQueue(Queue *inQueue) {
  initStack(&(inQueue->start), 64);
  initStack(&(inQueue->end), 64);
}

void enqueue(Queue *inQueue, int value) {
  push(&(inQueue->start), value);
}

int dequeue(Queue *inQueue) {
  int value = 0;
  if (inQueue->end.length > 0) {
    return pop(&(inQueue->end));
  }
  while(1) { 
    value = pop(&(inQueue->start));
    if (value == -1) {
      break;
    }
    push(&(inQueue->end), value);
  }
  
  return pop(&(inQueue->end));
}
