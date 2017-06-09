#include "tree.h"
#include <stdio.h>

int main() {
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
	int i = 0;
	for(i = 1;i < 6;i++) {
          printf("level %d: ", i);
	  printLevel(myTree, i);
	  printf("\n");
	}
        /*
	printLevel(myTree, 3);
	printf("\n");
        */
	
	
	return 0;
}
