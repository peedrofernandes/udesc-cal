#include "../headers/sorting.h"

void merge(Train *A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  Train L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = A[p + i];
  for (int j = 0; j < n2; j++)
    R[j] = A[q + 1 + j];

  int i = 0, j = 0, k = p;
  while (i < n1 && j < n2) {
    if (L[i].departTimeMilliseconds <= R[j].departTimeMilliseconds)
      A[k++] = L[i++];
    else
      A[k++] = R[j++];
  }
  while (i < n1)
    A[k++] = L[i++];
  while (j < n2)
    A[k++] = R[j++];
}
void mergeSortRecursive(Train *A, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    mergeSortRecursive(A, p, q);
    mergeSortRecursive(A, q + 1, r);
    merge(A, p, q, r);
  }
}
void mergeSortTrains(Train *arr, int size) {
  mergeSortRecursive(arr, 0, size - 1);
}