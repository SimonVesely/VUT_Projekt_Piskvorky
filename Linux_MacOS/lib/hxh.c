#include "../include/checker.h"
#include "../include/mylib.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void humanXhuman() {
  clearScreen();
  int rows = 3, cols = 3, pocetTahu = 0, aktHrac = 1, konecHry = 0, remiza = 0;
  char jmeno1[256], jmeno2[256], choice[256], empty[256], vstup[256];
  char a1[] = "   ", a2[] = "   ", a3[] = "   ", b1[] = "   ", b2[] = "   ",
       b3[] = "   ", c1[] = "   ", c2[] = "   ", c3[] = "   ";
  ascii();
  printf("Zadej jméno hráč č.1: ");
  scanf("%s", jmeno1);
  clearScreen();
  ascii();
  printf("Zadej jméno hráč č.2: ");
  scanf("%s", jmeno2);

  while (konecHry == 0) {
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

    printf("\n\nHráč č.1: %s |" RED "X" RESET "|    Hráč č.2: %s |" BLUE
           "O" RESET "|",
           jmeno1, jmeno2);
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
        chooser(a1, &aktHrac);
        break;
      case '2':
        chooser(a2, &aktHrac);
        break;
      case '3':
        chooser(a3, &aktHrac);
        break;
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
        chooser(b1, &aktHrac);
        break;
      case '2':
        chooser(b2, &aktHrac);
        break;
      case '3':
        chooser(b3, &aktHrac);
        break;
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
        chooser(c1, &aktHrac);
        break;
      case '2':
        chooser(c2, &aktHrac);
        break;
      case '3':
        chooser(c3, &aktHrac);
        break;
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
    case 'q':
      return;
    case 'Q':
      return;
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
    konecHry = checker(konecHry, a1, a2, a3, b1, b2, b3, c1, c2, c3);
    remiza = draw(a1, a2, a3, b1, b2, b3, c1, c2, c3);
  }
  clearScreen();
  if (remiza == 1) {
    printf("Nastala remíza, chcete opakovat hru(1) nebo odejít do menu(2): ");
    scanf("%s", vstup);
    if (vstup[0] == '1') {
      humanXhuman();
    }
  } else {
    if (aktHrac == 2) {
      printf("Gratulujeme, vyhrál hráč č.1, %s\n\nChcete opakovat hru(1) nebo "
             "odejít do menu(2): ",
             jmeno1);
      scanf("%s", vstup);
      if (vstup[0] == '1') {
        humanXhuman();
      }

    } else {
      printf("Gratulujeme, vyhrál hráč č.2, %s\n\nChcete opakovat hru(1) nebo "
             "odejít do menu(2): ",
             jmeno2);
      scanf("%s", vstup);
      if (vstup[0] == '1') {
        humanXhuman();
      }
    }
  }
  return;
}
