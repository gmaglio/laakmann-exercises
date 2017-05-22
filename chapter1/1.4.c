#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 4
#define STR "ABCD"

void swap(char *a, char *b) {
  *b = *a ^ *b;
  *a = *a ^ *b;
  *b = *a ^ *b;
}

int factorial(int n) {
  int i = 0;
  int result = 1;
  for (i = n; i > 0; i--) {
    result = result * i;  
  }
  return result;
}

int main() {
  int maxPerms = factorial(STRLEN);
  char *str = malloc(STRLEN*sizeof(char));
  memcpy(str, STR, STRLEN);

  int permCounter = 0;
  int strPos = 1;
  for (permCounter = 0; permCounter < maxPerms/2; permCounter++) {
    strPos = ((strPos + 1) % (STRLEN - 1)); 
    swap(&str[0], &str[strPos+1]);
    printf(":%s\n", str);
  }

  for (permCounter = 0; permCounter < maxPerms/4; permCounter++) {
    strPos = ((strPos + 1) % (STRLEN - 1));
    swap(&str[STRLEN-1], &str[strPos]);
    printf(":%s\n", str);
  }

  return 0;
}
