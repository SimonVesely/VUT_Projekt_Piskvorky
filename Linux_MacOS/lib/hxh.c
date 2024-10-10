#include "../include/mylib.h"
#include <stdio.h>
#include <unistd.h>

void humanXhuman() {
  clearScreen();
  int rows = 3, cols = 3, pocetTahu = 0, aktHrac = 1;
  char jmeno1[256], jmeno2[256], choice[256];
  char a1[]="  ", a2[]="  ", a3[]="  ", b1[]="  ", b2[]="  ", b3[]="  ", c1[]="  ", c2[]="  ", c3[]="  ";
  printf("Zadej jméno hráč č.1: ");
  scanf("%s", jmeno1);
  clearScreen();
  printf("Zadej jméno hráč č.2: ");
  scanf("%s", jmeno2);

  while (pocetTahu != 9) {
    clearScreen();
    int x = 0, y = 0;
    printf("Hrací pole:           |           Ukázkové pole:\n"
           " --------------       |           -------------- \n"
           "| %s | %s | %s |      |          | A1 | A2 | A3 |\n"
           "|----|----|----|      |          |----|----|----|\n"
           "| %s | %s | %s |      |          | B1 | B2 | B3 |\n"
           "|----|----|----|      |          |----|----|----|\n"
           "| %s | %s | %s |      |          | C1 | C2 | C3 |\n"
           " --------------       |           -------------- \n", a1, a2, a3, b1, b2, b3, c1, c2, c3);
    

    printf("\n\nHráč č.1: %s     Hráč č.2: %s", jmeno1, jmeno2);
    if(aktHrac == 1){
      printf("Výběr pole: (Hráč č.%d/%s)", aktHrac, jmeno1);
      scanf("%s", choice);
      aktHrac = 2;
    } else {
      printf("\n\nVýběr pole: (Hráč č.%d/%s): ", aktHrac, jmeno2);
      scanf("%s", choice);
      aktHrac = 1;
    }
  }
  return;
}
