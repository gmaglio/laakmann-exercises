#include "../lib/list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void insertIntHead(NodeInt **head, int data) {
  assert(*head != NULL);
  NodeInt *new_head = malloc(sizeof(NodeInt));
  new_head->next = *head;
  new_head->data = data;
  *head = new_head;
}

void insertIntLast(NodeInt *head, int data) {
  assert(head != NULL);
  NodeInt *itr = head;
  while (itr->next != NULL) {
    itr = itr->next;
  }
  itr->next = malloc(sizeof(NodeInt));
  itr->data = data;
}

int lengthIntList(NodeInt *head) {
  int counter = 0;
  NodeInt *itr = head;
  for(itr = head; itr->next != NULL; itr = itr->next) {
    counter++;
  }
  return counter;
}

int deleteIntHead(NodeInt **head) {
  int data = (*head)->data;
  NodeInt *old_head = *head;
  *head = (*head)->next;
  free(old_head);
  return data;
}

int deleteIntLast(NodeInt *head) {
  NodeInt *itr = head;
  do { 
    itr = itr->next;
  } while (itr->next->next != NULL);
  int data = itr->data;
  NodeInt *tmp = itr->next;
  itr->next = NULL;
  free(tmp);
  return data;
}

void getLastElementsChar(NodeInt *head, int k) {
  int counter = 0;

  printf("last %d elements from list: ", k);

  while(head->next != NULL) {
    if (counter >= k) {
      printf("%c", head->data);
      if (head->next->next != NULL) {
        printf(" -> ");
      }
    }
    counter++;
    head = head->next;
  }
  printf("\n");
}

int peekIntHead(NodeInt *head) {
  return head->data;
}

int peekIntLast(NodeInt *head) {
  NodeInt *itr = head;
  do { 
    itr = itr->next;
  } while (itr->next->next != NULL);
  return itr->data;
}

void getIntPosLast(
  NodeInt **dest_head, 
  NodeInt *src_head,
  int pos
) {
  int counter = 0;
  NodeInt *itr = src_head;
  while (itr->next != NULL) {
    if (counter >= pos) {
      insertIntHead(dest_head, itr->data);
    }
    itr=itr->next;
    counter++;
  }
}

void getIntHeadPos(
  NodeInt *dest_head, 
  NodeInt *src_head,
  int pos
) {
  int counter = 0;
  NodeInt *itr = src_head;
  while (itr->next != NULL) {
    if (counter < pos) {
      insertIntLast(dest_head, itr->data);
    }
    itr=itr->next;
    counter++;
  }
}


void printIntList(NodeInt *head) {
  assert(head != NULL);
  NodeInt *itr = head;
  for(itr = head; itr->next != NULL; itr = itr->next) {
    printf("%c", itr->data);
    if (itr->next->next != NULL) {
      printf(" -> ");
    }
  }
  printf("\n");
}

int compareIntOrderedLists(NodeInt *head_a, NodeInt *head_b) {
  if (lengthIntList(head_a) != lengthIntList(head_b)) {
    return 0;
  }
  NodeInt *itr_a = head_a;
  NodeInt *itr_b = head_b;
  while(itr_a->next != NULL) {
    itr_a = itr_a->next;
    itr_b = itr_b->next;
    if (itr_a->data != itr_b->data) {
      return 0;
    }
  }
  return 1;
}

void strToList(NodeInt *head, char *str, int length) {
  int pos = 0;
  for (pos = 0; pos < length; pos++) {
    insertIntLast(head, str[pos]);
  }
}
