#include <stdio.h>

int recursiveFibonacci(int n) {
  if (n <= 2)
    return 1;

  return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);]
}

int main() {
  int n;

  printf("Type the nth term of fibonacci: ");
  scanf("%d", &n);

  
}