#include "../lib/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 2.
int isPalindrome (List list) {
  int length = lengthIntList(list);

  List list_a;
  initList(&list_a);

  List list_b;
  initList(&list_b);

  if ((length % 2) == 0) {
    getIntHeadPos(&list_a, list, length/2);
    getIntPosLast(&list_b, list, length/2);
  }
  return compareIntOrderedLists(list_a, list_b); 
}

// 2.1
int removeDups (List list) {
  int asciiMap[128];
  int counter = 0;
  for (;counter <= 128; counter++) {
    asciiMap[counter] = 0;
  }
  
  // asciiMap['e'] = 1;
  while (list.head->next != NULL) {
    if (asciiMap[list.head->data]) {
      NodeInt *tmp = list.head;
      list.head = list.head->next;
      free(tmp); 
    } else {
      asciiMap[list.head->data] = 1;
      list.head = list.head->next;
    }
  }
}

// 2.5
List sumLists(List a, List b) {
  NodeInt *itr_a = a.head;
  NodeInt *itr_b = b.head;
  List resultList;

  initList(&resultList);

  int result, carry = 0;
  while (itr_a->next != NULL || itr_b->next != NULL) {
    result = itr_a->data + itr_b->data + carry;
    if (result > 10) {
      carry = 1;
      insertIntLast(&resultList, result - 10);
    } else {
      carry = 0;
      insertIntLast(&resultList, result);
    }
    itr_a = itr_a->next;
    itr_b = itr_b->next;
  }
  if (carry > 0) {
    insertIntLast(&resultList, carry);
  }
  return resultList;
}

// 2.7
NodeInt *find_intersection(List a, List b) {
  NodeInt *itr_a = a.head;
  NodeInt *itr_b = b.head;

  for(itr_a;itr_a->next != NULL;itr_a = itr_a->next) {
    for(itr_b;itr_b->next != NULL;itr_b = itr_b->next) {
      if (itr_a == itr_b && (itr_a != NULL || itr_b != NULL)) {
        return itr_a;
      }
    }
  }
  return NULL;
}


int main() {
  List list_a;
  initList(&list_a);

  List list_b;
  initList(&list_b);

  insertIntLast(&list_a, 2);
  insertIntLast(&list_a, 3);
  insertIntLast(&list_a, 4);
  insertIntLast(&list_a, 1);
  
  insertIntLast(&list_b, 7);
  insertIntLast(&list_b, 4);
  insertIntLast(&list_b, 7);
  insertIntLast(&list_b, 8);

  list_a.head->next->next = list_b.head->next->next;

  printIntList(list_a);
  printIntList(list_b);

  printIntList(sumLists(list_a, list_b));
  NodeInt *intersection = find_intersection(list_a, list_b);
  printf("Intersection: %d", intersection->data);


  return 0;
}
