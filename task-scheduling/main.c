/*
Considere uma estação de trem com n plataformas e dois trilhos ferroviários principais para ambas as
direções. Os trens que precisam parar nessa estação devem ocupar uma plataforma para sua parada e os trens
que não precisam parar nessa estação podem percorrer qualquer um dos dois trilhos sem parar.
Cada trem tem três valores: horário de chegada, horário de partida e número da plataforma de parada.
Recebendo o número de plataformas da estação, o número de trens e os dados de cada trem, crie um algoritmo que calcule o número máximo de trens que podem parar nessa estação.

Entrada: 
  n: Número de plataformas
  t: Número de trens
  T[]: Dados de cada trem (horário de chegada, horário de partida, nº da plataforma)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct train {
  int id;
  int arriveTimeInMinutes;
  int departTimeInMinutes;
  int nPlatform;
} Train;

char* getStrArray(char* str, int size) {
  int resultSize = size + (size - 1) + 2;
  char *result = malloc(resultSize * sizeof(char));

  result[0] = '[';

  int i = 1;
  int cur = 0;
  while (i < resultSize - 1) {
    if (i % 2 == 1) {
      result[i] = str[cur];
      cur++;
    } else
      result[i] = ',';

    i++;
  }
  result[resultSize - 1] = ']';

  return result;
}

void inputNumber(int* num) {
  scanf("%d", num);
  getchar();
}

void inputString(char* str, int maxSize) {
  fgets(str, maxSize, stdin);
  int len = strlen(str);
  if (str[len - 1] == '\n')
    str[len - 1] = '\0';
}

void handleInputError(char *errorString) {
  printf("Erro - %s\n", errorString);
  exit(1);
}

void verifyStrDigits(char* str, int size) {
  for (int i = 0; i < size; i++) {
    if (isdigit(str[i]) == 0) {
      printf("Erro - String não contem apenas dígitos.\n");
      exit(1);
    }
  }
}

int main() {
  int n, t;
  printf("Digite o número de plataformas da estação: ");
  inputNumber(&n);

  printf("Digite o número de trens desejado: ");
  inputNumber(&t);

  if (n <= 0 || t <= 0)
    handleInputError("Quantidade inválida de plataformas e/ou trens.");

  Train *trens = malloc(t * sizeof(Train));

  for (int i = 0; i < t; i++) {
    printf("\n------------------------------ TREM %d ------------------------------\n\n", i);
    trens[i].id = i + 1;
    printf("Digite o número da plataforma: ");
    inputNumber(&trens[i].nPlatform);

    if (trens[i].nPlatform < 1 || trens[i].nPlatform > n)
      handleInputError("Numero de plataforma inválido.");

    char timeStr[6];
    char tmpTimeStr[6];


    printf("Digite o horário de chegada do trem (hh:mm): ");
    inputString(timeStr, 6);
    printf("Horario digitado: %s\n", getStrArray(timeStr, 6));

    memcpy(tmpTimeStr, timeStr, 6);

    char *hStr = strtok(timeStr, ":");
    char *mStr = strtok(NULL, ":");

    printf("hStr: %s, size: %d\n", hStr, (int)sizeof(hStr));
    printf("mStr: %s, size: %d\n", mStr, (int)sizeof(mStr));

    if (hStr == NULL || mStr == NULL)
      handleInputError("Formato de hora inválido!");

    verifyStrDigits(hStr, 2);
    verifyStrDigits(mStr, 2);

    printf("timeString: %s\n", timeStr);
    printf("hourString: %s\n", hStr);
    printf("minuteString: %s\n", mStr);
  }
}