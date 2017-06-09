#include <stdio.h>

int fib(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fib(n - 1) + fib(n - 2); // A 
}

int main() {
  int i = 0;
  const SIZE = 10;
  for (i = 0; i < SIZE; i++) {
    printf("fib(%d): %d\n", i, fib(i));
  }
  return 0;
}

