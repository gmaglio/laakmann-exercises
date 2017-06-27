#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct _node_int {
  struct _node_int *next;
  int data;
} NodeInt;

typedef struct _node_char {
  struct _node_char *next;
  int data;
} NodeChar;

typedef struct _list {
  NodeInt *head;
  size_t length;
} List;

void initList(List *list);

void insertIntHead(List *list, int data);
void insertIntLast(List *list, int data);
void insertIntPosition(List list, int pos, int data);

int deleteIntHead(List *list);
int deleteIntLast(List *list);
void deleteIntMiddle(List *list, int data);

int peekIntHead(List list);
int peekIntLast(List list);

int popIntHead(List list, int data); // will use peekHead and deleteHead;
int popIntLast(List list, int data); // will use peekLast and deleteLast;

void getLastElementsChar(List list, int k);

void getIntPosLast(
  List *dest_list, 
  List src_list,
  int pos
);
void getIntHeadPos(
  List *dest_list,
  List src_list,
  int pos
);

void printIntList(List list);

int compareIntOrderedLists(List list_a, List list_b);

void strToList(List *list, char *str, int length);

#endif
