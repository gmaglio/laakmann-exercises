#include "SetOfStacks.h"
#include "stack.h"
#include <assert.h>
#include <stdlib.h>

void SetOfStacksInit (SetOfStacks *stacks) {
  stacks->currStackIdx = 0;
  stacks->stackSet[stacks->currStackIdx] = malloc(sizeof(Stack));
  initStack(stacks->stackSet[stacks->currStackIdx], GLOBAL_STACK_SIZE);
}

void SetOfStacksPush (SetOfStacks *stacks, int value) {
  if (push(stacks->stackSet[stacks->currStackIdx], value) == 1) {
    stacks->stackSet[++stacks->currStackIdx] = malloc(sizeof(Stack));
    initStack(stacks->stackSet[stacks->currStackIdx], GLOBAL_STACK_SIZE);
    assert(push(stacks->stackSet[stacks->currStackIdx], value) == 0);
  }
}

int SetOfStacksPop (SetOfStacks *stacks) {
  int value = pop(stacks->stackSet[stacks->currStackIdx]);
  if (stacks->currStackIdx == 0 && value == -1) {
    return -1;
  }
  if (value == -1) {
    free(stacks->stackSet[stacks->currStackIdx]);
    return pop(stacks->stackSet[--stacks->currStackIdx]);
  }
  return value;
}
