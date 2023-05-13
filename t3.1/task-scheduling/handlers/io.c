#include "../headers/io.h"
#include <stdio.h>
#include <string.h>

void printArray(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i != size - 1) printf(",");
  }
  printf("]\n");
}

void printArrayStr(char* str) {
  printf("[");
  int i = 0;
  while (str[i] != '\0') {
    printf("%c,", str[i]);
    i++;
  }
  printf("\\0]\n");
}

void inputString(char* str, int maxSize) {

  fgets(str, maxSize, stdin);
  int len = strlen(str);
  if (str[len - 1] == '\n')
    str[len - 1] = '\0';

  // clear buffer
  getchar();
}

void inputInt(int* n) {
  scanf("%d", n);
  getchar();
}