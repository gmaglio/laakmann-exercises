#include "../lib/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 2.
int isPalindrome (NodeInt *head) {
  int length = lengthIntList(head);

  NodeInt *list_a = malloc(sizeof(NodeInt));
  list_a->next = NULL;

  NodeInt *list_b = malloc(sizeof(NodeInt));
  list_b->next = NULL;

  if ((length % 2) == 0) {
    getIntHeadPos(list_a, head, length/2);
    getIntPosLast(&list_b, head, length/2);
  }
  return compareIntOrderedLists(list_a, list_b); 
}

// 2.1
int removeDups (NodeInt *head) {
  int asciiMap[128];
  int counter = 0;
  for (;counter <= 128; counter++) {
    asciiMap[counter] = 0;
  }
  
  // asciiMap['e'] = 1;
  while (head->next != NULL) {
    if (asciiMap[head->data]) {
      NodeInt *tmp = head;
      head = head->next;
      free(tmp); 
    } else {
      asciiMap[head->data] = 1;
      head = head->next;
    }
  }
}       

int main() {
  NodeInt *list_a = malloc(sizeof(NodeInt));
  list_a->next = NULL;
  
  NodeInt *list_b = malloc(sizeof(NodeInt));
  list_b->next = NULL;
  
  NodeInt *list_c = malloc(sizeof(NodeInt));
  list_c->next = NULL;

  char str[13] = "Elaina_anialE";
  strToList(list_a, str, 13);

  char str2[12] = "GreegeerG";
  strToList(list_b, str2, 9);

  printIntList(list_b);
  removeDups(list_b);
  printIntList(list_a);

  printf("isPalindrome: %i\n", isPalindrome (list_a));
  getLastElementsChar(list_a, 5);
  return 0;
}
