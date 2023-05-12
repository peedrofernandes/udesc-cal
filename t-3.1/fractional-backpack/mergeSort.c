#include <stdlib.h>
#include <string.h>
#include "mergeSort.h"

void merge(void* A, int p, int q, int r, int elemSize, int (*comp)(void*, void*)) {
  int n1 = q - p + 1;
  int n2 = r - q;
  void* L = malloc(n1 * elemSize);
  void* R = malloc(n2 * elemSize);

  memcpy(L, A + p * elemSize, n1 * elemSize);
  memcpy(R, A + (q + 1) * elemSize, n2 * elemSize);

  int i = 0, j = 0, k = p;
  while (i < n1 && j < n2) {
    if (comp(L + i * elemSize, R + j * elemSize) <= 0) // L[i] <= R[j]
      memcpy(A + k++ * elemSize, L + i++ * elemSize, elemSize);
    else // L[i] > R[j]
      memcpy(A + k++ * elemSize, R + j++ * elemSize, elemSize);
  }

  while (i < n1)
    memcpy(A + k++ * elemSize, L + i++ * elemSize, elemSize);
  while (j < n2)
    memcpy(A + k++ * elemSize, R + j++ * elemSize, elemSize);

  free(L);
  free(R);
}

void mergeSortRecursive(void* A, int p, int r, int elemSize, int (*comp)(void*, void*)) {
  if (p < r) {
    int q = (p + r) / 2;
    mergeSortRecursive(A, p, q, elemSize, comp);
    mergeSortRecursive(A, q + 1, r, elemSize, comp);
    merge(A, p, q, r, elemSize, comp);
  }
}

void mergeSort(void* arr, int size, int elemSize, int (*comp)(void*, void*)) {
  mergeSortRecursive(arr, 0, size - 1, elemSize, comp);
}