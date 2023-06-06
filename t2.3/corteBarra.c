#include <stdio.h>
#include <stdlib.h>

int corteBarraBottomUp(int *p, int n) {
  int B[n];

  for (int k = 0; k < n; k++) {
    int lucro = p[k];
    for (int i = 0; i < k; i++) {
      int valor = p[i] + B[k - i - 1];
      if (valor > lucro)
        lucro = valor;
    }
    B[k] = lucro;
  }

  return B[n - 1];
}

int corteBarraTopDownRecursivo(int *p, int *B, int k) {
  if (B[k] == -1) {
    int lucro = p[k];

    for (int i = 1; i < k; i++) {
      int valor = p[i] + corteBarraTopDownRecursivo(p, B, k - i);
      if (valor > lucro)
        lucro = valor;
    }

    B[k] = lucro;
  }

  return B[k];
}

int corteBarraTopDown(int *p, int n) {
  int B[n];
  B[0] = p[0];
  for (int i = 1; i < n; i++)
    B[i] = -1;
  return corteBarraTopDownRecursivo(p, B, n - 1);
}

int main() {
  int arr[10] = {1, 5, 2, 19, 3, 4, 15, 18, 49, 60};

  printf("%d\n", corteBarraTopDown(arr, 10));
}