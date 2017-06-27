#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "Hello,World,welcome,to,my,hell";
  const char delim[] = ",";
  char *tok = strtok(str, ",");
  while (tok) {
    printf("%s\n", tok);
    tok = strtok(NULL, ",");
  }
  return 0;
}
