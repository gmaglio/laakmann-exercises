#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./stdlib.h"

#define INIT_STRLEN 10

void fillSegment(char *str, int startPos, int endPos) {
  int currPos = 0;
  for (currPos = startPos; currPos < endPos; currPos++) {
    str[currPos] = ' ';
  }
}

void shiftString(char *str, int startPos, int n, int strlen) {
  int currPos = 0;
  str = realloc(str, strlen+n);
  for (currPos = strlen+n; currPos > startPos; currPos--) {
    str[currPos] = str[currPos-n]; 
  }
  fillSegment(str, currPos, currPos+n);
}
