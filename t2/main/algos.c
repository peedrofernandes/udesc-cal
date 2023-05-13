#include "algos.h"

void insertionSort(int *v, int n, int *q) {
  for (int i = 0; i < n; i++) {
    *q += 3;

    int j = i;
    while (j > 0 && v[j - 1] > v[j]) {
      *q += 5;

      int aux = v[j];
      v[j] = v[j - 1];
      v[j - 1] = aux;
      j--;
    }
    *q += 1;
  }
}

void bubbleSort(int *v, int n, int *q) {
  for (int j = n - 1; j >= 0; j--) {
    *q += 2;
    for (int i = 0; i < j; i++) {
      *q += 2;
      if (v[i] > v[i + 1]) {
        int aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }

    }
  }
}

void quickSort(int *v, int n, int *q) {
  *q += 1;

  int j = -1;

  for (int i = 0; i < n; i++) {
    *q += 3;
    if (v[i] > v[n - 1]) continue;

    j++;
    *q += 2;
    if (i > j) {
      *q += 3;
      int aux = v[i];
      v[i] = v[j];
      v[j] = aux;
    }

  }

  *q += 1;
  if (n <= 1) return;

  *q += 2;
  quickSort(&v[0], j, q);
  quickSort(&v[j + 1], n - 1 - j, q);
}

void merge(int *A, int l, int m, int r, int *q) {
  *q += 7;

  // Juntar dois sub-arrays de A, sendo eles A[l..m] e A[m+1..r]

  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Criar arrays temporários L e R
  int L[n1], R[n2];

  // Copiar os dados para os vetores temporários L e R
  *q += 1;
  for (i = 0; i < n1; i++) {
    L[i] = A[l + i];
    *q += 3;
  }
  *q += 1;
  for (j = 0; j < n2; j++) {
    R[j] = A[m + 1 + j];
    *q += 3;
  }

  // Juntar os vetores de volta em A[p..q]
  i = 0; // Índice inicial do primeiro subarray
  j = 0; // Índice inicial do segundo subarray
  k = l; // Índice inicial do array que foi juntado
  *q += 1;
  while (i < n1 && j < n2) {
    *q += 2;
    if (L[i] <= R[j]) {
      *q += 3;
      A[k] = L[i];
      i++;
    } else {
      *q += 3;
      A[k] = R[j];
      j++;
    }
    k++;
  }

  // Copiar os valores restantes de L[] e R[], se existirem
  *q += 1;
  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
    *q += 4;
  }
  *q += 1;
  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
    *q += 4;
  }
}
void mergeSortRecursive(int *A, int l, int r, int *q) {
  *q += 1;
  if (l < r) {
    *q += 6;

    int m = l + (r - l) / 2;

    mergeSortRecursive(A, l, m, q);
    mergeSortRecursive(A, m + 1, r, q);

    merge(A, l, m, r, q);
  }
}
void mergeSort(int *v, int n, int *q) {
  *q += 1;
  mergeSortRecursive(v, 0, n - 1, q);
}

void heapify(int *vetor, int n, int i, int *q) {
  *q += 3;

  int raiz = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;
  *q += 1;
  if (esquerda < n && vetor[esquerda] > vetor[raiz]) {
    raiz = esquerda;
    *q += 1;
  }
  *q += 1;
  if (direita < n && vetor[direita] > vetor[raiz]) {
    raiz = direita;
    *q += 1;
  }
  *q += 1;
  if (raiz != i) {
    int aux = vetor[i];
    vetor[i] = vetor[raiz];
    vetor[raiz] = aux;

    heapify(vetor, n, raiz, q);
    *q += 4;
  }
}
void heapSort(int *v, int n, int *q) {
  *q += 2;
  for (int i = (n / 2) - 1; i >= 0; i--) {
    *q += 3;
    heapify(v, n, i, q);
  }

  *q += 2;
  for (int j = n - 1; j > 0; j--) {
    *q += 6;
    int aux = v[0];
    v[0] = v[j];
    v[j] = aux;

    heapify(v, j, 0, q);
  }
}

int linearSearch(int *v, int n, int key, int *q) {
  *q += 1;
  int indexFound = -1;

  *q += 2;
  for (int i = 0; i < n; i++) {
    *q += 3;
    if (v[i] == key) {
      *q += 2;
      indexFound = i;
      break;
    }
  }

  *q += 1;
  return indexFound;
}

int binarySearch(int *v, int n, int key, int *q) {
  *q += 4;

  int indexFound = -1;

  int l = 0, r = n - 1;
  int i = (r + l) / 2;

  *q += 1;
  while (l <= r) {
    *q += 1;

    *q += 1;
    if (v[i] == key) {
      *q += 3;
      indexFound = i;
      break;
    }

    *q += 1;
    if (key > v[i]) {
      *q += 2;
      l = i + 1;
    }
    else {
      *q += 2;
      r = i - 1;
    }

    *q += 1;
    i = (r + l) / 2;
  }

  *q += 1;
  return indexFound;
}