#ifndef LIST_H
#define LIST_H

typedef struct _node_int {
  struct _node_int *next;
  int data;
} NodeInt;

typedef struct _node_char {
  struct _node_char *next;
  int data;
} NodeChar;

void insertIntHead(NodeInt **head, int data);
void insertIntLast(NodeInt *head, int data);
void insertIntPosition(NodeInt *head, int pos, int data);

int deleteIntHead(NodeInt **head);
int deleteIntLast(NodeInt *head);
int deleteIntPosition(NodeInt *head, int pos, int data);

int peekIntHead(NodeInt *head);
int peekIntLast(NodeInt *head);

int popIntHead(NodeInt *head, int data); // will use peekHead and deleteHead;
int popIntLast(NodeInt *head, int data); // will use peekLast and deleteLast;

int lengthIntList(NodeInt *head);

void printIntList(NodeInt *head);

#endif
