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
  char jmeno1[256], jmeno2[256], choice[256], empty[256];
  char a1[] = "   ", a2[] = "   ", a3[] = "   ", b1[] = "   ", b2[] = "   ",
       b3[] = "   ", c1[] = "   ", c2[] = "   ", c3[] = "   ";
  printf("Zadej jméno hráč č.1: ");
  scanf("%s", jmeno1);
  clearScreen();
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

    printf("\n\nHráč č.1: %s |"RED"X"RESET"|    Hráč č.2: %s |"BLUE"O"RESET"|", jmeno1, jmeno2);
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
        if (a1[1] == 'X' || a1[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
        if (aktHrac == 2) {
          strcpy(a1, " X ");
          break;
        } else {
          strcpy(a1, " O ");
          break;
        }
      case '2':
        if (a2[1] == 'X' || a2[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
        if (aktHrac == 2) {
          strcpy(a2, " X ");
          break;
        } else {
          strcpy(a2, " O ");
          break;
        }
      case '3':
        if (a3[1] == 'X' || a3[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
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
        if (b1[1] == 'X' || b1[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
        if (aktHrac == 2) {
          strcpy(b1, " X ");
          break;
        } else {
          strcpy(b1, " O ");
          break;
        }
      case '2':
        if (b2[1] == 'X' || b2[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
        if (aktHrac == 2) {
          strcpy(b2, " X ");
          break;
        } else {
          strcpy(b2, " O ");
          break;
        }
      case '3':
        if (b3[1] == 'X' || b3[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
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
        if (c1[1] == 'X' || c1[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
        if (aktHrac == 2) {
          strcpy(c1, " X ");
          break;
        } else {
          strcpy(c1, " O ");
          break;
        }
      case '2':
        if (c2[1] == 'X' || c2[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
        if (aktHrac == 2) {
          strcpy(c2, " X ");
          break;
        } else {
          strcpy(c2, " O ");
          break;
        }
      case '3':
        if (c3[1] == 'X' || c3[1] == 'O') {
          printf("Toto pole už bylo zvoleno!\n");
          sleep(1);
          if (aktHrac == 2) {
            aktHrac = 1;
          } else {
            aktHrac = 2;
          }
          break;
        }
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
    printf("Nastala remíza, chcete opakovat hru nebo odejít do menu: ");
  } else {
    if (aktHrac == 2) {
      printf("Gratulujeme, vyhrál hráč č.1, %s\n", jmeno1);
    } else {
      printf("Gratulujeme, vyhrál hráč č.2, %s\n", jmeno2);
    }
  }
  scanf("%s", empty);
  return;
}
