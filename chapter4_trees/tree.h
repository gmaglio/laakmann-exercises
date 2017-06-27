#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

#include "../lib/list.h"

typedef struct _tree {
	struct _tree *left, *right;
	int value;
} tree;

size_t size = 0;

void initTree(tree **head, int value);
void insertTree(tree **head, int value);
void printTree(tree *head);

void initTree(tree **head, int value) {
  *head = malloc(sizeof(tree));
  (*head)->value = value;
  (*head)->left = NULL;
  (*head)->right = NULL;
}

void insertTree(tree **head, int value) {
  if(*head == NULL) {
    *head = malloc(sizeof(tree));
    (*head)->value = value;
    (*head)->left = NULL;
    (*head)->right = NULL;
    return;
  }
  if(value < (*head)->value) {
    insertTree(&((*head)->left), value);
  }
  else {
    insertTree(&((*head)->right), value);
  }
}

void printTree(tree *head) {
  if(head->left != NULL) {
    printf("%d ", head->left->value);
  } 
  if(head->right != NULL) {
    printf("%d ", head->right->value);
  }
  printTree(head->left);
  printTree(head->right);
}


void printLevel(tree *head, size_t level) {
  if(head == NULL) {
    return;
  }
  if(level == 1) {
    printf("%d ", head->value);
  }
  printLevel(head->left, level-1);
  printLevel(head->right, level-1);
}

void transverseTree(tree *head) {
  if(head->left != NULL) {
    printf("%d ", head->left->value);
  } 
  if(head->right != NULL) {
    printf("%d ", head->right->value);
  }
  printTree(head->left);
  printTree(head->right);
}

List insertLevel(tree *head, size_t level, List *arr[]) {
  if(level == 1) {
    return head->value;
  }
  insertLevel(head->left, level-1, arr);
  insertLevel(head->right, level-1, arr);
}

#endif
