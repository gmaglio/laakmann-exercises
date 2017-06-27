#include "tree.h"
#include <stdio.h>
#include "../lib/list.h"

void allocLists (List *arr[], unsigned int length) {
  int counter = 0;
  for (counter = 0; counter < length; counter++){
    arr[counter] = malloc(sizeof(List));
  }
};

int main() {
  List *depthList[16];
  allocLists(depthList, 16);
  tree *myTree = NULL;
  initTree(&myTree, 23);
  insertTree(&myTree, 45);
  insertTree(&myTree, 32);
  insertTree(&myTree, 56);
  insertTree(&myTree, 3);
  insertTree(&myTree, 77);
  insertTree(&myTree, 53);
  insertTree(&myTree, 1);
  insertTree(&myTree, 2);
  int i = 2;
  insertLevel(myTree, i, depthList); 
  // printIntList(*(depthList[1]));
  printf("\n");
  return 0;
}
