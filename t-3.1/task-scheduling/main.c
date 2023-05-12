/*
Considere uma estação de trens com n plataformas e 2 trilhos ferroviários.
Os trens que precisam parar durante um período nessa estação ocuparão, pelo tempo
desse período, uma das n plataformas. Outros trens não serão bloqueados porque usarão
o outro trilho como desvio. Cada trem tem horário de chegada, horário de saída e
plataforma requisitada. Sendo assim, crie um algoritmo que, dados a quantidade de
plataformas, quantidade de trens e dados de cada trem, calcule o número máximo de trens
que a plataforma suportará.
*/

// OBS: Para rodar o programa, use o comando ./run.sh OU gcc main.c handlers/* -o main && ./main

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "headers/schedulingTypes.h"
#include "headers/aux.h"
#include "headers/io.h"
#include "headers/sorting.h"

int calculateQtdTrains(Train *trains, int nTrains, int nPlatforms) {
  Train** trainsByPlatform = malloc(nPlatforms * sizeof(Train*));
  int qtdTrainsByPlatform[nPlatforms];
  for (int i = 0; i < nPlatforms; i++) {
    trainsByPlatform[i] = malloc(32 * sizeof(Train));
    qtdTrainsByPlatform[i] = 0;
  }

  // Attach each train to its corresponding train-by-platform array
  for (int i = 0; i < nTrains; i++) {
    int platformIndex = trains[i].nPlatform - 1;
    trainsByPlatform[platformIndex][qtdTrainsByPlatform[platformIndex]] = trains[i];
    qtdTrainsByPlatform[platformIndex]++;
    if (qtdTrainsByPlatform[platformIndex] > 32)
      throwError("Quantidade maxima de trens por plataforma (32) atingida.");
  }

  // Execution of the scheduling method for each train-by-platform array
  int totalTrains = 0;
  for (int i = 0; i < nPlatforms; i++) {
    int qtdTrainsInPlatform = qtdTrainsByPlatform[i];
    Train* currentTrainList = trainsByPlatform[i];

    mergeSortTrains(currentTrainList, qtdTrainsInPlatform);
    int qtdTrains = 1;
    int fk = currentTrainList[0].departTimeMilliseconds;
    for (int j = 1; j < qtdTrains; j++) {
      if (currentTrainList[j].arriveTimeMilliseconds >= fk)
        qtdTrains++;
    }

    totalTrains += qtdTrains;
  }

  return totalTrains;
}

int main() {
  int n, t;

  printf("---------------- ESTAÇÃO DE TRENS ----------------\n\n");

  printf("Digite a quantidade de plataformas: ");
  inputInt(&n);

  printf("Digite a quantidade de trens: ");
  inputInt(&t);

  if (n <= 0 || t <= 0)
    throwError("Quantidade inválida de plataformas e/ou trens.");

  Train* trains = malloc(t * sizeof(Train));

  printf("Números válidos para plataformas: [");
  for (int i = 0; i < n; i++) {
    printf("%d", i + 1);
    if (i != n - 1) printf(",");
  }
  printf("]\n");

  for (int i = 0; i < t; i++) {
    printf("\n---------------- TREM %d ----------------\n\n", i + 1);

    // Id
    trains[i].id = i + 1;

    // Plataforma
    printf("Digite a plataforma do trem: ");
    inputInt(&trains[i].nPlatform);
    if (trains[i].nPlatform < 1 || trains[i].nPlatform > n)
      throwError("Número inválido de plataforma.");

    // Horário de chegada
    char arriveTimeStr[6];
    printf("Digite o horário de chegada do trem: ");
    inputString(arriveTimeStr, 6);
    int* arriveTime = getTimeFromString(arriveTimeStr);
    trains[i].arriveTimeMilliseconds = getMilliseconds(arriveTime[0], arriveTime[1]);

    // Horário de saída
    char departTimeStr[6];
    printf("Digite o horário de saída do trem: ");
    inputString(departTimeStr, 6);
    int* departTime = getTimeFromString(departTimeStr);
    trains[i].departTimeMilliseconds = getMilliseconds(departTime[0], departTime[1]);

    if (trains[i].departTimeMilliseconds < trains[i].arriveTimeMilliseconds)
      throwError("O tempo de saída não pode ser anterior ao tempo da entrada!\n");

    free(arriveTime);
    free(departTime);
  }

  int qtdTrains = calculateQtdTrains(trains, t, n);
  printf("Quantidade de trens suportada: %d\n", qtdTrains);

  return 0;
}