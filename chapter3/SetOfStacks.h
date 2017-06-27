#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H

#include "stack.h"

#define SETSIZE 1024
#define GLOBAL_STACK_SIZE 3

typedef struct _setofstacks {
  Stack *stackSet[SETSIZE];
  unsigned int currStackIdx;
} SetOfStacks;

void SetOfStacksInit (SetOfStacks *stacks);
void SetOfStacksPush (SetOfStacks *stacks, int value);
int SetOfStacksPop (SetOfStacks *stacks);
int SetOfStacksTop (SetOfStacks *stacks);

#endif
