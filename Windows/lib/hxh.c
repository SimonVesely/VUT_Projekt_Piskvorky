#include "../include/checker.h"
#include "../include/mylib.h"
#include "../include/leaderboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

void humanXhuman() {
  clearScreen();
  int velikostPole;
  int aktHrac = 1, konecHry = 0, remiza = 0;
  char jmeno1[256], jmeno2[256], choice[256], vstup[256];

  ascii();
  printf("Zadej jméno hráč č.1: ");
  scanf("%s", jmeno1);
  clearScreen();
  ascii();
  printf("Zadej jméno hráč č.2: ");
  scanf("%s", jmeno2);
  clearScreen();
  ascii();
  printf("Vyber si velikost pole (3 - 9): ");
  scanf("%d", &velikostPole);
  char hracipole[9][9];
  for (int i = 0; i < velikostPole; i++) {
    for (int j = 0; j < velikostPole; j++) {
      hracipole[i][j] = '.';
    }
  }

  while (konecHry == 0) {
    clearScreen();
    if (aktHrac == 1) {
      printf(RED "Y\n" RESET);
    } else {
      printf(BLUE "Y\n" RESET);
    }
    printf("^\n|   ");
    for (int i = 0; i < velikostPole; i++) {
      printf("---");
    }
    for (int i = 0; i < velikostPole - 1; i++) {
      printf("-");
    }
    printf("\n");

    for (int i = 0; i < velikostPole; i++) {
      printf("%d  ", i + 1);
      for (int j = 0; j < velikostPole; j++) {
        if (j == velikostPole - 1) {
          if (hracipole[i][j] == '.') {
            printf("| " GREEN "%c" RESET " |\n", hracipole[i][j]);
          } else if (hracipole[i][j] == 'X') {
            printf("| " RED "%c" RESET " |\n", hracipole[i][j]);
          } else if (hracipole[i][j] == 'O') {
            printf("| " BLUE "%c" RESET " |\n", hracipole[i][j]);
          }

        } else {
          if (hracipole[i][j] == '.') {
            printf("| " GREEN "%c" RESET " ", hracipole[i][j]);
          } else if (hracipole[i][j] == 'X') {
            printf("| " RED "%c" RESET " ", hracipole[i][j]);
          } else if (hracipole[i][j] == 'O') {
            printf("| " BLUE "%c" RESET " ", hracipole[i][j]);
          }
        }
      }
      if (i != velikostPole - 1) {
        printf("|  |");
        for (int i = 0; i < velikostPole; i++) {
          printf("---|");
        }
        printf("\n");
      }
    }

    printf("|   ");
    for (int i = 0; i < velikostPole; i++) {
      printf("---");
    }
    for (int i = 0; i < velikostPole - 1; i++) {
      printf("-");
    }
    printf("\n*---");
    for (int i = 0; i < velikostPole; i++) {
      printf("-%d--", i + 1);
    }
    for (int i = 0; i < velikostPole - 1; i++) {
      printf("-");
    }
    printf(">");
    if (aktHrac == 1) {
      printf(RED "X\n" RESET);
    } else {
      printf(BLUE "X\n" RESET);
    }

    printf("\n\nHráč č.1: %s |" RED "X" RESET "|    Hráč č.2: %s |" BLUE
           "O" RESET "|        Q - Ukončení hry / R - Restart hry",
           jmeno1, jmeno2);

    if (aktHrac == 1) {
      printf("\n\nVýběr pole: (Hráč č.%d/%s) |X;Y|: ", aktHrac, jmeno1);
      scanf("%s", choice);
      aktHrac = 2;
    } else {
      printf("\n\nVýběr pole: (Hráč č.%d/%s) |X;Y|: ", aktHrac, jmeno2);
      scanf("%s", choice);
      aktHrac = 1;
    }

    if (strlen(choice) == 2) {
      int row = choice[0] - '1'; // Convert character to 0-based index
      int col = choice[1] - '1'; // Convert character to 0-based index

      if (row >= velikostPole || col >= velikostPole || row < 0 || col < 0) {
        printf("Špatný vstup !!!\n");
        sleep(1);
        if (aktHrac == 1) {
          aktHrac = 2;
        } else {
          aktHrac = 1;
        }
      } else {
        if (hracipole[row][col] == 'X' || hracipole[row][col] == 'O') {
          printf("Pole je již obsazeno! Zkuste jiné místo.\n");
          sleep(1);
          if (aktHrac == 1) {
            aktHrac = 2;
          } else {
            aktHrac = 1;
          }
          sleep(2);
        } else {
          if (aktHrac == 2) {
            hracipole[row][col] = 'X'; // Assign 'X' for player 2
          } else {
            hracipole[row][col] = 'O'; // Assign 'O' for player 1
          }
        }
      }
    } else {
      printf("Špatný vstup !!!\n");
      if (aktHrac == 1) {
        aktHrac = 2;
      } else {
        aktHrac = 1;
      }
    }

    if (checker(hracipole, velikostPole, 'X') == 1) {
      konecHry++;
    } else if (checker(hracipole, velikostPole, 'O') == 1) {
      konecHry++;
    }
    int rem_check = 0;
    for (int i = 0; i < velikostPole; i++) {
      for (int j = 0; j < velikostPole; j++) {
        if (hracipole[i][j] == '.') {
          rem_check++;
        }
      }
    }
    if (rem_check == velikostPole*velikostPole) {
      remiza++;
      konecHry++;
    }
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
      if (checker_lb(jmeno1) == 1){
        overwriter_lb(jmeno1);
      } else {
        writer_lb(jmeno1);
      }
      printf("Gratulujeme, vyhrál hráč č.1, %s\n\nChcete opakovat hru(1) nebo"
             "odejít do menu(2): ",
             jmeno1);
      scanf("%s", vstup);
      if (vstup[0] == '1') {
        humanXhuman();
      }
    } else {
      if (checker_lb(jmeno2) == 1){
        overwriter_lb(jmeno2);
      } else {
        writer_lb(jmeno2);
      }
      printf("Gratulujeme, vyhrál hráč č.2, %s\n\nChcete opakovat hru(1) nebo"
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
