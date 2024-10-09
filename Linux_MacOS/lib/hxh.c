#include "../include/mylib.h"
#include <stdio.h>
#include <unistd.h>

void humanXhuman() {
  clearScreen();
  int rows = 3, cols = 3, pocetTahu = 0, aktHrac = 1;
  char jmeno1[256], jmeno2[256], hraciPole[2][2][2], choice[256],
      ukazkovePole[3][3][3] = {
          {"A1", "A2", "A3"}, {"B1", "B2", "B3"}, {"C1", "C2", "C3"}};
  printf("Zadej jméno hráč č.1: ");
  scanf("%s", jmeno1);
  clearScreen();
  printf("Zadej jméno hráč č.2: ");
  scanf("%s", jmeno2);

  while (pocetTahu != 9) {
    clearScreen();
    int x = 0, y = 0;
    puts("Ukázkové pole:");
    for (int i = 0; i < rows; i++) {
      if (x == 0) {
        puts("\n____________");
        x++;
      }
      for (int j = 0; j < cols; j++) {
        printf("|%s ", ukazkovePole[i][j]);
        if ((y == 2) || (y == 5) || (y == 8)) {
          printf("|");
        }
        y++;
      }
      if ((x == 1) || (x == 2)) {
        puts("\n|---|---|---|");
        x++;
      }
    }
    puts("\n------------");

    puts("\n\nHrací pole");

    printf("\n\nHráč č.1: %s     Hráč č.2: %s                   ", jmeno1, jmeno2);
    if(aktHrac == 1){
      printf("Výběr pole: (Hráč č.%d/%s)", aktHrac, jmeno1);
      scanf("%s", choice);
      aktHrac = 2;
    } else {
      printf("Výběr pole: (Hráč č.%d/%s)", aktHrac, jmeno2);
      scanf("%s", choice);
      aktHrac = 1;
    }
  }
  return;
}
