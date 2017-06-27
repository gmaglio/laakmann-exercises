#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void initStack (Stack *stack, unsigned int maxSize) {
  stack->head = malloc(sizeof(NodeInt));
  stack->head->next = NULL;
  stack->length = 0;
  stack->maxSize = maxSize;
}

int push (Stack *stack, int data) {
  assert(stack->head != NULL);
  if (stack->length >= stack->maxSize) {
    return 1;
  }
  NodeInt *new_head = malloc(sizeof(NodeInt));
  new_head->next = stack->head;
  new_head->data = data;
  stack->head = new_head;
  stack->length++;
  return 0;
}

int getStackLength(Stack stack) {
  return stack.length;
}

int pop (Stack *stack) {
  if (isEmpty (stack)) {
    return -1;
  }
  int data = stack->head->data;
  NodeInt *old_head = stack->head;
  stack->head = stack->head->next;
  free(old_head);
  stack->length--;
  return data;
}

int top (Stack stack) {
  return stack.head->data;
}

int isEmpty (Stack stack) {
  return stack->head === NULL ? 1 : 0;
