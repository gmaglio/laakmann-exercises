#include "../lib/list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  NodeInt *list_a = malloc(sizeof(NodeInt));

  insertIntLast(list_a, 5);
  insertIntLast(list_a, 6);
  insertIntLast(list_a, 7);
  insertIntLast(list_a, 8);
  insertIntLast(list_a, 9);
  insertIntLast(list_a, 10);
  insertIntLast(list_a, 11);
  insertIntHead(&list_a, -1);
  insertIntHead(&list_a, -2);
  insertIntHead(&list_a, -3);

  printIntList(list_a);

  printf("Head: %i\n", peekIntHead(list_a));
  printf("Last: %i\n", peekIntLast(list_a));
  printf("Length: %i\n", lengthIntList(list_a));
  printf("Delete Head: %i\n", deleteIntHead(&list_a));
  printf("Delete Head: %i\n", deleteIntHead(&list_a));
  printf("Delete Head: %i\n", deleteIntHead(&list_a));
  printf("Head: %i\n", peekIntHead(list_a));
  printf("Last: %i\n", peekIntLast(list_a));
  printf("Delete Last: %i\n", deleteIntLast(list_a));
  printf("Last: %i\n", peekIntLast(list_a));
  printf("Delete Last: %i\n", deleteIntLast(list_a));
  printf("Last: %i\n", peekIntLast(list_a));
  printf("Delete Last: %i\n", deleteIntLast(list_a));
  printf("Last: %i\n", peekIntLast(list_a));
  printf("Length: %i\n", lengthIntList(list_a));
  return 0;
}
