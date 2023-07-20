#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStrTillTheEnd(char* str) {
  printf("[");
  int cur = 0;
  while (str[cur] != '\0') {
    printf("%c,", str[cur]);
    cur++;
  }
  printf("\\0]\n");
}

void inputString(char* str, int maxSize) {
  fgets(str, maxSize, stdin);
  printf("String capturada pelo fgets: ");
  printStrTillTheEnd(str);
  int len = strlen(str);
  if (str[len - 1] == '\n')
    str[len - 1] = str[len]; // Tirar o /n do final da string
}

int main() {
  char s1[5] = "pedro";

  char s2[5] = "faria";

  char s3[9] = "fernandes";

  printStrTillTheEnd(s1);
  printStrTillTheEnd(s2);
  printStrTillTheEnd(s3);

  char *str = malloc(6 * sizeof(char));
  printf("Digite uma string qualquer: ");
  inputString(str, 6);

  printStrTillTheEnd(str);
  printf("Tamanho da string digitada: %d\n", (int)strlen(str));
}