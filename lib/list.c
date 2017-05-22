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

void printIntList(NodeInt *head) {
  assert(head != NULL);
  NodeInt *itr = head;
  for(itr = head; itr->next != NULL; itr = itr->next) {
    printf("%i\n", itr->data);
  }
}
