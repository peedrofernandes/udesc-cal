#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergeSort.h"

typedef struct item {
  int id;
  int weight;
  int value;
} Item;

typedef struct term {
  int id;
  double value;
} Term;

// void printArray(int* arr, int size) {
//   printf("[");
//   for (int i = 0; i < size; i++) {
//     printf("%d", arr[i]);
//     if (i != size - 1)
//       printf(",");
//   }
//   printf("]\n");
// }

void printTerms(Term* terms, int size) {
  printf("[\n");
  for (int i = 0; i < size; i++) {
    printf("  {\n");
    printf("    \"id\": \"%d\",\n", terms[i].id);
    printf("    \"value\": \"%.4lf\"\n", terms[i].value);
    printf("  }\n");
  }
  printf("]\n");
}

int compareItemsByProportion(void* a, void* b) {
  Item i1 = *(Item *)a;
  Item i2 = *(Item *)b;

  double proportion1 = (double)i1.value / (double)i1.weight;
  double proportion2 = (double)i2.value / (double)i2.weight;

  if (proportion1 > proportion2)
    return 1;
  if (proportion1 == proportion2)
    return 0;
  return -1;
}

Item* createItems(int* p, int* v, int size) {
  Item* items = malloc(size * sizeof(Item));

  for (int i = 0; i < size; i++) {
    items[i].id = i + 1;
    items[i].value = v[i];
    items[i].weight = p[i];
  }

  return items;
}

Term* fractionalBackpack(Item* items, int n, int w) {
  Term *terms = malloc(n * sizeof(Term));
  int c = w;

  mergeSort(items, n, sizeof(Item), compareItemsByProportion);
  for (int j = n - 1; j >= 0; j--) {
    terms[j].id = items[j].id;
    int currentWeight = items[j].weight;
    if (c >= currentWeight) {
      c -= currentWeight;
      terms[j].value = 1;
    } else {
      terms[j].value = (double)c / (double)currentWeight;
      c = 0;
    }
  }

  return terms;
}

int main() {
  int p[5] = {10, 20, 30, 20, 40};
  int v[5] = {100, 300, 600, 400, 840};

  Item *items = createItems(p, v, 5);

  Term *terms = fractionalBackpack(items, 5, 50);
  printTerms(terms, 5);

  free(terms);
}