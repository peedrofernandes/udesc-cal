#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int dynamicFibRecursiveTopDown(int *A, int n, int logs) {
  if (A[n] == -1) {
    if (logs)
      printf("Calculando fibonacci de %d...\n", n);

    A[n] = dynamicFibRecursiveTopDown(A, n - 1, logs) + dynamicFibRecursiveTopDown(A, n - 2, logs);
  }

  return A[n];
}

int dynamicFibTopDown(int n, int logs) {
  int A[n];
  A[0] = 1;
  A[1] = 1;
  for (int i = 2; i < n; i++)
    A[i] = -1;
  return dynamicFibRecursiveTopDown(A, n - 1, logs);
}

int dynamicFibBottomUp(int n, int logs) {
  int A[n];
  A[0] = 1;
  A[1] = 1;
  for (int i = 2; i < n; i++) {
    if (logs)
      printf("Calculando fibonacci de %d...\n", i);
    A[i] = A[i - 1] + A[i - 2];
  }
  return A[n - 1];
}

int fib(int n, int logs) {
  if (logs)
    printf("Calculando fibonacci de %d...\n", n);

  if (n <= 2) return 1;

  return fib(n - 1, logs) + fib(n - 2, logs);
}

int main() {
  int opAlg;
  char opLogs;

  do {
    printf("Selecione :\n");
    printf("[0] Usar o algoritmo de fibonacci normal;\n");
    printf("[1] Usar o algoritmo de fibonacci com programação dinâmica Top Down;\n");
    printf("[2] Usar o algoritmo de fibonacci com programação dinâmica Bottom Up;\n");
    printf("Sua opção: ");
    scanf("%d", &opAlg);

    if (opAlg != 0 && opAlg != 1 && opAlg != 2)
      printf("Opção inválida.\n");
  } while (opAlg != 0 && opAlg != 1 && opAlg != 2);

  getchar();

  do {
    char op;
    printf("Deseja exibir logs do andamento do algoritmo? [Ss/Nn] - ");
    scanf("%c", &op);
    opLogs = tolower(op);

    if (opLogs != 's' && opLogs != 'n')
      printf("Opção inválida.\n");
  } while (opLogs != 's' && opLogs != 'n');

  int logs = opLogs == 's' ? 1 : 0;

  int n;
  printf("Digite o enésimo termo de fibonacci (máx. 50) - ");
  scanf("%d", &n);

  if (n > 50) {
    printf("Erro - Valor muito grande.\n");
    exit(1);
  }

  printf("Calculando...\n");
  int result = opAlg == 0 ? 
    fib(n, logs) : 
    opAlg == 1 ? 
    dynamicFibTopDown(n, logs) : 
    dynamicFibBottomUp(n, logs);

  printf("Resultado: %d\n", result);
}