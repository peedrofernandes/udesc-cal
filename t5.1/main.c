#include <stdio.h>
#include "intBackpack.h"

int main() {
  int n = 4;
  int W = 7;
  int P[] = {1, 3, 4, 5};
  int V[] = {10, 40, 50, 70};

  printf("%d\n", intBackpackBottomUp(n, W, P, V));
}