#include <stdio.h>
#define STRLEN 28

int isPermutation(char *str1, char *str2) {
  int strpos = 0;  // current position at each string
  int str1sum = 0; // sum of values in str1
  int str2sum = 0; // sum of values in str2

  for (strpos = 0; strpos < STRLEN; strpos++) {
    str1sum  += (int) str1[strpos]; 
  } 
  for (strpos = 0; strpos < STRLEN; strpos++) {
    str2sum  += (int) str2[strpos]; 
  } 
  if (str1sum == str2sum) {
    return 1; // true
  }
  return 0; // false
}

int main() {
  char str[STRLEN] = "Elaina,Iloveyou!";
  char str2[STRLEN] = "vloanaiE,Ioleyu!";

  printf("isPermutation: %i\n", isPermutation(str, str2));
    
  return 0;
}
