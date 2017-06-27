#include "Queue.h"
#include <stdio.h>
#include "stack.h"

int main() {
  Queue myQueue;

  initQueue(&myQueue);
  enqueue(&myQueue, 31);
  enqueue(&myQueue, 34);
  enqueue(&myQueue, 51);
  enqueue(&myQueue, 84);
  enqueue(&myQueue, 90);
  enqueue(&myQueue, 93);

  printf("dequeue: %i\n", dequeue(&myQueue));
  enqueue(&myQueue, 104);
  printf("dequeue: %i\n", dequeue(&myQueue));
  printf("dequeue: %i\n", dequeue(&myQueue));
  printf("dequeue: %i\n", dequeue(&myQueue));
  printf("dequeue: %i\n", dequeue(&myQueue));
  printf("dequeue: %i\n", dequeue(&myQueue));
  printf("dequeue: %i\n", dequeue(&myQueue));

  
  return 0;
}
