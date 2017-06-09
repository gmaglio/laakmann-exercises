#ifndef HASH_H
#define HASH_H

#define TABLE_SIZE 26;

typedef struct dataItem {
  int data;
  int key;
} dataItem;

int hashCode (int key) {
  return key % TABLE_SIZE;
}
#endif

