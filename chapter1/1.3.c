#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 32

char insertString(char *str, char *src, int startPos, int length) {
  int curPos = 0;
  int absPos = 0;
  for (absPos = 0, curPos = startPos; curPos < startPos+length+1; curPos++, absPos++) {
    str[curPos] = src[absPos];
  } 
}

char *urlify(char *str, int strlen) {
  int curPos = 0;  // current position at each string
  char blankString[3] = "%20";

  for (curPos = 0; curPos < strlen; curPos++) {
    if((int) str[curPos] == 32) {
      shiftString(str, curPos, 3, strlen);
      insertString(str, blankString, curPos, 3);
    }
  } 
}

int main() {
  char *str = malloc(sizeof(char)*STRLEN);
  memcpy(str, "Elaina, I love you!", STRLEN);

  printf("string: %s\n", str);
  urlify(str, STRLEN);
  printf("after urlify: %s\n", str);
    
  return 0;
}
