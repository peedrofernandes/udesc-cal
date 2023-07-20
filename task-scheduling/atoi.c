#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  char *str = "12";
  char *str2 = "34";

  printf("%d\n", atoi(str) + atoi(str2));

  char *str3 = "ab";
  printf("%d\n", atoi(str3));

  printf("%d\n", isdigit(str[0]));
  printf("%d\n", isdigit(str[1]));
  printf("%d\n", isdigit(str3[0]));
}