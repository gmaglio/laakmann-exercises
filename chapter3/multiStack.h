#define SIZE 1024 // the size of the underlying store
#define NUMSTACKS 3 // the number of stacks

typedef struct _multiStack {
  // Index that specifies the current top of each stack
  int stackPtr[NUMSTACKS];

  // Where each stack begins
  // Must be maintained as immutable
  int framePtr[NUMSTACKS];

  int stackSize;

  // The underlying store for all the stacks
  int store[SIZE]; 
} MultiStack;

void initMultiStack (MultiStack *mStack) {
  mStack->stackSize = SIZE / NUMSTACKS;
  int i = 0;

  /* Initialize the stack and frame pointers 
  of each stack */
  for (i = 0; i < NUMSTACKS; i++) {
    mStack->stackPtr[i] = mStack->stackSize * i;
    mStack->framePtr[i] = mStack->stackSize * i;
  } 
}

int pushMultiStack (MultiStack *mStack, unsigned int stackSpec, int value) {
  if (mStack->stackPtr[stackSpec] >= mStack->framePtr[stackSpec] + mStack->stackSize) {
    printf("Cannot push because we're at the end of stack\n");
    return 1;
  } 
  mStack->store[mStack->stackPtr[stackSpec]] = value;
  mStack->stackPtr[stackSpec]++;
} 

int popMultiStack (MultiStack *mStack, unsigned int stackSpec) {
  if (mStack->stackPtr[stackSpec] <= mStack->framePtr[stackSpec]) {
    printf("Cannot pop because stack is empty\n");
    return 1;
  }
  mStack->stackPtr[stackSpec]--;
  int value = mStack->store[mStack->stackPtr[stackSpec]];
  mStack->store[mStack->stackPtr[stackSpec]] = 0;
  return value;
}
