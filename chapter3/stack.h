#ifndef STACK_H
#define STACK_H

typedef struct _node_int {
  struct _node_int *next;
  int data;
} NodeInt;

typedef struct _stack {
  NodeInt *head;
  unsigned int length;
  unsigned int maxSize;
} Stack;

void initStack (Stack *stack, unsigned int maxSize);
int push (Stack *stack, int data);
int pop (Stack *stack);
int top (Stack stack);
int isEmpty (Stack stack);

#endif
