#include <stdio.h>
#include "./intBackpack.h"

int max(int a, int b) {
  return a >= b ? a : b;
}

void printMatrix(int x, int y, int M[x][y]) {
  for (int i = 0; i < x; i++) {
    printf("[");
    for (int j = 0; j < y; j++) {
      printf("%02d", M[i][j]);
      if (j != y - 1)
        printf(" ");
    }
    printf("]\n");
  }
}

int intBackpackBottomUp(int n, int W, int *P, int *V) {
  // n = Qty. of elements
  // W = Capacity of the backpack
  // P = Weights of each element (array)
  // V = Values of each element (array)
  
  int M[n + 1][W + 1];
  // M[n][W]: Great solution for a int backpack with n elements and remaining capacity W 

  for (int i = 0; i < n + 1; i++)
    M[i][0] = 0;
  for (int i = 0; i < W + 1; i++)
    M[0][i] = 0;
  // M[j][0] must be 0 because there's no remaining space at the backpack
  // M[0][W] must be 0 because there's no remaining items to add at the backpack 

  for (int i = 1; i < n + 1; i++) {
    int wi = P[i - 1];
    int vi = V[i - 1];
    for (int X = 1; X < W + 1; X++) {

      if (wi > X) {
        M[i][X] = M[i - 1][X];
        // Here, the weight of the element is bigger than the capacity. The only possible
        // solution is to not use the element.
      } else {
        M[i][X] = max(vi + M[i - 1][X - wi], M[i - 1][X]);
        // Here, the great solution is the maximum between the solution using the element and
        // not using the element.
      }
    }
  }

  printMatrix(n + 1, W + 1, M);

  return M[n][W];
}