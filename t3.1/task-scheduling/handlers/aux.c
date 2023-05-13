#include "../headers/aux.h"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void throwError(char* errorMessage) {
  printf("Erro!\n%s\n", errorMessage);
  exit(1);
}

int stringIsNumber(char* str) {
  char cur = 0;
  while (str[cur] != '\0') {
    if (!isdigit(str[cur]))
      return 0;
    cur++;
  }

  return 1;
}

int *getTimeFromString(char* str) {
  char *p1 = strtok(str, ":");
  char *p2 = strtok(NULL, ":");

  int p1IsValid = p1 != NULL && stringIsNumber(p1) && (atoi(p1) >= 0 && atoi(p1) <= 23);
  int p2IsValid = p2 != NULL && stringIsNumber(p2) && (atoi(p2) >= 0 && atoi(p2) <= 59);
  if (!(p1IsValid && p2IsValid)) {
    throwError("Formato inválido de tempo!");
  }

  int* result = malloc(2 * sizeof(int));
  result[0] = atoi(p1);
  result[1] = atoi(p2);
  return result;
}

int getMilliseconds(int hours, int minutes) {
  return hours * 60 * 60 * 1000 + minutes * 60 * 1000;
}