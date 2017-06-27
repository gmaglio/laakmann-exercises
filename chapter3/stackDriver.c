#include <stdio.h>
#include "SetOfStacks.h"

int main() {
 
  SetOfStacks myStacks;
  SetOfStacksInit(&myStacks);

  SetOfStacksPush(&myStacks, 3);
  SetOfStacksPush(&myStacks, 5);
  SetOfStacksPush(&myStacks, 7);
  SetOfStacksPush(&myStacks, 2);
  SetOfStacksPush(&myStacks, 8);
  SetOfStacksPush(&myStacks, 12);
  SetOfStacksPush(&myStacks, 13);
  SetOfStacksPush(&myStacks, 23);
  SetOfStacksPush(&myStacks, 58);
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  printf("pop: %i\n", SetOfStacksPop(&myStacks));
  return;
}
