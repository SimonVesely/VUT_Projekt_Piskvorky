#include "mylib.h"
#include <stdio.h>
#include <unistd.h>

void humanXhuman() {
  clearScreen();
  int rows = 3, cols =3;
  char jmeno1[256], jmeno2[256], hraciPole[2][2][2],
      ukazkovePole[3][3][3] = {
          {"A1", "A2", "A3"}, {"B1", "B2", "B3"}, {"C1", "C2", "C3"}};
  printf("Zadej jméno hráč č.1: ");
  scanf("%s", jmeno1);
  printf("\nZadej jméno hráč č.2: ");
  scanf("%s", jmeno2);

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      printf("%s |", ukazkovePole[i][j]);
    }
    puts("");
  }

  sleep(3);
  return;
}
