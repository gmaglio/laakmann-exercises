#include <stdio.h>
#include "multiStack.h"

int main () {
  MultiStack mStack;
  initMultiStack(&mStack);
  pushMultiStack(&mStack, 0, 3);
  pushMultiStack(&mStack, 0, 56);
  pushMultiStack(&mStack, 0, 44);
  pushMultiStack(&mStack, 0, 63);
  pushMultiStack(&mStack, 1, 4);
  pushMultiStack(&mStack, 1, 8);
  pushMultiStack(&mStack, 1, 95);
  pushMultiStack(&mStack, 1, 50);

  printf("pop stack 0: %i\n", popMultiStack(&mStack, 0));
  printf("pop stack 0: %i\n", popMultiStack(&mStack, 0));
  printf("pop stack 0: %i\n", popMultiStack(&mStack, 0));
  printf("pop stack 0: %i\n", popMultiStack(&mStack, 0));
  printf("pop stack 0: %i\n", popMultiStack(&mStack, 0));

  printf("pop stack 1: %i\n", popMultiStack(&mStack, 1));
  printf("pop stack 1: %i\n", popMultiStack(&mStack, 1));
  printf("pop stack 1: %i\n", popMultiStack(&mStack, 1));
  printf("pop stack 1: %i\n", popMultiStack(&mStack, 1));
}
