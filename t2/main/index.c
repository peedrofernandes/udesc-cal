#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algos.h"

#define qtdEntries 15



// void printVet(int *v, int n) {
//   printf("[");
//   for (int i = 0; i < n; i++) {
//     printf("%d", v[i]);
//     if (i != n - 1)
//       printf(",");
//   }
//   printf("]\n");
// }

// #define insertionSortFile "files/insertionSort.txt"
// #define bubbleSortFile "files/bubbleSort.txt"
// #define quickSortFile "files/quickSort.txt"
// #define mergeSortFile "files/mergeSort.txt"
// #define heapSortFile "files/heapSort.txt"
// #define linearSearchFile "files/linearSearch.txt"
// #define binarySearchFile "files/binarySearch.txt"

int main() {
  srand(time(NULL));

  int entries[qtdEntries] = {10, 30, 50, 70, 90, 100, 300, 500, 700, 900, 1000, 3000, 5000, 7000, 9000};

  FILE *insertionSortFile = fopen("files/insertionSort.txt", "wt");
  FILE *bubbleSortFile = fopen("files/bubbleSort.txt", "wt");
  FILE *quickSortFile = fopen("files/quickSort.txt", "wt");
  FILE *mergeSortFile = fopen("files/mergeSort.txt", "wt");
  FILE *heapSortFile = fopen("files/heapSort.txt", "wt");
  FILE *linearSearchFile = fopen("files/linearSearch.txt", "wt");
  FILE *binarySearchFile = fopen("files/binarySearch.txt", "wt");

  if (insertionSortFile == NULL || bubbleSortFile == NULL || quickSortFile == NULL || mergeSortFile == NULL || heapSortFile == NULL || linearSearchFile == NULL || binarySearchFile == NULL) {
    printf("Erro na abertura de algum dos arquivos!\n");
    return 1;
  }

  for (int i = 0; i < qtdEntries; i++) {

    // Geração e população do vetor aleatório
    int randomVet[entries[i]];
    for (int j = 0; j < entries[i]; j++)
      randomVet[j] = abs(rand() % 100);

    int qtds[7] = {0, 0, 0, 0, 0, 0, 0};

    int randomVetCopy[entries[i]];

    // Algoritmos de ordenação

    // Insertion Sort
    memcpy(randomVetCopy, randomVet, entries[i] * sizeof(int));
    insertionSort(randomVetCopy, entries[i], &qtds[0]);
    fprintf(insertionSortFile, "%d, %d\n", entries[i], qtds[0]);

    // Bubble Sort
    memcpy(randomVetCopy, randomVet, entries[i] * sizeof(int));
    bubbleSort(randomVetCopy, entries[i], &qtds[1]);
    fprintf(bubbleSortFile, "%d, %d\n", entries[i], qtds[1]);

    // Quick Sort
    memcpy(randomVetCopy, randomVet, entries[i] * sizeof(int));
    quickSort(randomVetCopy, entries[i], &qtds[2]);
    fprintf(quickSortFile, "%d, %d\n", entries[i], qtds[2]);

    // Merge Sort
    memcpy(randomVetCopy, randomVet, entries[i] * sizeof(int));
    mergeSort(randomVetCopy, entries[i], &qtds[3]);
    fprintf(mergeSortFile, "%d, %d\n", entries[i], qtds[3]);

    // Heap Sort
    memcpy(randomVetCopy, randomVet, entries[i] * sizeof(int));
    heapSort(randomVetCopy, entries[i], &qtds[4]);
    fprintf(heapSortFile, "%d, %d\n", entries[i], qtds[4]);

    // Algoritmos de busca

    int randKey = abs(rand() % 100);

    // Linear Search
    memcpy(randomVetCopy, randomVet, entries[i] * sizeof(int));
    linearSearch(randomVetCopy, entries[i], randKey, &qtds[5]);
    fprintf(linearSearchFile, "%d, %d\n", entries[i], qtds[5]);

    // Binary Search
    binarySearch(randomVetCopy, entries[i], randKey, &qtds[6]);
    fprintf(binarySearchFile, "%d, %d\n", entries[i], qtds[6]);
  }

  fclose(insertionSortFile);
  fclose(bubbleSortFile);
  fclose(quickSortFile);
  fclose(mergeSortFile);
  fclose(heapSortFile);
  fclose(linearSearchFile);
  fclose(binarySearchFile);
}