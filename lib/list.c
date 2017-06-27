#include "../lib/list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void initList(List *list) {
  list->head = malloc(sizeof(NodeInt));
  list->head->next = NULL;
  list->length = 0;
}

void insertIntHead(List *list, int data) {
  assert(list->head != NULL);
  NodeInt *new_head = malloc(sizeof(NodeInt));
  new_head->next = list->head;
  new_head->data = data;
  list->head = new_head;
  list->length++;
}

void insertIntLast(List *list, int data) {
  assert(list->head != NULL);
  NodeInt *itr = list->head;
  while (itr->next != NULL) {
    itr = itr->next;
  }
  itr->next = malloc(sizeof(NodeInt));
  itr->data = data;
  list->length++;
}

int lengthIntList(List list) {
  return list.length;
}

int deleteIntHead(List *list) {
  int data = list->head->data;
  NodeInt *old_head = list->head;
  list->head = list->head->next;
  free(old_head);
  list->length--;
  return data;
}

// 2.3
void deleteIntMiddle(List *list, int data) {
  NodeInt *itr = list->head;
  NodeInt *old_node = NULL;
  do {
    if (itr->next->data == data && 
        itr->next->next != NULL) {
      old_node = itr->next;
      itr->next = itr->next->next;
      free(old_node);

    } else {
      itr = itr->next;
    }
  } while (itr->next->next != NULL);
}

int deleteIntLast(List *list) {
  NodeInt *itr = list->head;
  do { 
    itr = itr->next;
  } while (itr->next->next != NULL);
  int data = itr->data;
  NodeInt *tmp = itr->next;
  itr->next = NULL;
  free(tmp);
  list->length--;
  return data;
}

void getLastElementsChar(List list, int k) {
  int counter = 0;

  printf("last %d elements from list: ", k);

  while(list.head->next != NULL) {
    if (counter >= (list.length - k)) {
      printf("%c", list.head->data);
      if (list.head->next->next != NULL) {
        printf(" -> ");
      }
    }
    counter++;
    list.head = list.head->next;
  }
  printf("\n");
}

int peekIntHead(List list) {
  return list.head->data;
}

int peekIntLast(List list) {
  NodeInt *itr = list.head;
  do { 
    itr = itr->next;
  } while (itr->next->next != NULL);
  return itr->data;
}

void getIntPosLast(
  List *dest_list, 
  List src_list,
  int pos
) {
  int counter = 0;
  NodeInt *itr = src_list.head;
  while (itr->next != NULL) {
    if (counter >= pos) {
      insertIntHead(dest_list, itr->data);
    }
    itr=itr->next;
    counter++;
  }
}

void getIntHeadPos(
  List *dest_list, 
  List src_list,
  int pos
) {
  int counter = 0;
  NodeInt *itr = src_list.head;
  while (itr->next != NULL) {
    if (counter < pos) {
      insertIntLast(dest_list, itr->data);
    }
    itr=itr->next;
    counter++;
  }
}

void printIntList(List list) {
  assert(list.head != NULL);
  NodeInt *itr = list.head;
  for(itr = list.head; itr->next != NULL; itr = itr->next) {
    printf("%i", itr->data);
    if (itr->next->next != NULL) {
      printf(" -> ");
    }
  }
  printf("\n");
}

int compareIntOrderedLists(List list_a, List list_b) {
  if (lengthIntList(list_a) != lengthIntList(list_b)) {
    return 0;
  }
  NodeInt *itr_a = list_a.head;
  NodeInt *itr_b = list_b.head;
  while(itr_a->next != NULL) {
    itr_a = itr_a->next;
    itr_b = itr_b->next;
    if (itr_a->data != itr_b->data) {
      return 0;
    }
  }
  return 1;
}

void strToList(List *list, char *str, int length) {
  int pos = 0;
  for (pos = 0; pos < length; pos++) {
    insertIntLast(list, str[pos]);
  }
}
