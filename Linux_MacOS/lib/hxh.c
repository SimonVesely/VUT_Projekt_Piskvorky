#include "../include/mylib.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void humanXhuman() {
  clearScreen();
  int rows = 3, cols = 3, pocetTahu = 0, aktHrac = 1;
  char jmeno1[256], jmeno2[256], choice[256];
  char a1[] = "   ", a2[] = "   ", a3[] = "   ", b1[] = "   ", b2[] = "   ",
       b3[] = "   ", c1[] = "   ", c2[] = "   ", c3[] = "   ";
  printf("Zadej jméno hráč č.1: ");
  scanf("%s", jmeno1);
  clearScreen();
  printf("Zadej jméno hráč č.2: ");
  scanf("%s", jmeno2);

  while (pocetTahu != 9) {
    clearScreen();
    int x = 0, y = 0;
    printf("Hrací pole:        |           Ukázkové pole:\n"
           " -----------       |           -------------- \n"
           "|%s|%s|%s|      |          | A1 | A2 | A3 |\n"
           "|---|---|---|      |          |----|----|----|\n"
           "|%s|%s|%s|      |          | B1 | B2 | B3 |\n"
           "|---|---|---|      |          |----|----|----|\n"
           "|%s|%s|%s|      |          | C1 | C2 | C3 |\n"
           " -----------       |           -------------- \n",
           a1, a2, a3, b1, b2, b3, c1, c2, c3);

    printf("\n\nHráč č.1 X: %s     Hráč č.2 O: %s", jmeno1, jmeno2);
    if (aktHrac == 1) {
      printf("\n\nVýběr pole: (Hráč č.%d/%s): ", aktHrac, jmeno1);
      scanf("%s", choice);
      aktHrac = 2;
    } else {
      printf("\n\nVýběr pole: (Hráč č.%d/%s): ", aktHrac, jmeno2);
      scanf("%s", choice);
      aktHrac = 1;
    }

    switch (choice[0]) {
    case 'a':
      switch (choice[1]) {
      case '1':
        if (aktHrac == 2) {
          strcpy(a1, " X ");
          break;
        } else {
          strcpy(a1, " O ");
          break;
        }
      case '2':
        if (aktHrac == 2) {
          strcpy(a2, " X ");
          break;
        } else {
          strcpy(a2, " O ");
          break;
        }
      case '3':
        if (aktHrac == 2) {
          strcpy(a3, " X ");
          break;
        } else {
          strcpy(a3, " O ");
          break;
        }
      default:
        printf("Špatný vstup!\n");
        sleep(1);
        if (aktHrac == 2) {
          aktHrac = 1;
        } else {
          aktHrac = 2;
        }
        break;
      }
      break;
    case 'b':
      switch (choice[1]) {
      case '1':
        if (aktHrac == 2) {
          strcpy(b1, " X ");
          break;
        } else {
          strcpy(b1, " O ");
          break;
        }
      case '2':
        if (aktHrac == 2) {
          strcpy(b2, " X ");
          break;
        } else {
          strcpy(b2, " O ");
          break;
        }
      case '3':
        if (aktHrac == 2) {
          strcpy(b3, " X ");
          break;
        } else {
          strcpy(b3, " O ");
          break;
        }
      default:
        printf("Špatný vstup!\n");
        sleep(1);
        if (aktHrac == 2) {
          aktHrac = 1;
        } else {
          aktHrac = 2;
        }
        break;
      }
      break;
    case 'c':
      switch (choice[1]) {
      case '1':
        if (aktHrac == 2) {
          strcpy(c1, " X ");
          break;
        } else {
          strcpy(c1, " O ");
          break;
        }
      case '2':
        if (aktHrac == 2) {
          strcpy(c2, " X ");
          break;
        } else {
          strcpy(c2, " O ");
          break;
        }
      case '3':
        if (aktHrac == 2) {
          strcpy(c3, " X ");
          break;
        } else {
          strcpy(c3, " O ");
          break;
        }
      default:
        printf("Špatný vstup!\n");
        sleep(1);
        if (aktHrac == 2) {
          aktHrac = 1;
        } else {
          aktHrac = 2;
        }
        break;
      }
    default:
      printf("Špatný vstup!\n");
      sleep(1);
      if (aktHrac == 2) {
        aktHrac = 1;
      } else {
        aktHrac = 2;
      }
      break;
    }
  }
  return;
}
