#include <stdio.h>
#include <string.h>
#include <unistd.h>

int checker(int konec, char a1[], char a2[], char a3[], char b1[], char b2[],
            char b3[], char c1[], char c2[], char c3[]) {
  if (a1[1] == 'X' && a2[1] == 'X' && a3[1] == 'X') {
    return 1;
  }
  if (b1[1] == 'X' && b2[1] == 'X' && b3[1] == 'X') {
    return 1;
  }
  if (c1[1] == 'X' && c2[1] == 'X' && c3[1] == 'X') {
    return 1;
  }
  if (a1[1] == 'X' && b1[1] == 'X' && c1[1] == 'X') {
    return 1;
  }
  if (a2[1] == 'X' && b2[1] == 'X' && c2[1] == 'X') {
    return 1;
  }
  if (a3[1] == 'X' && b3[1] == 'X' && c3[1] == 'X') {
    return 1;
  }
  if (a1[1] == 'X' && b2[1] == 'X' && c3[1] == 'X') {
    return 1;
  }
  if (a3[1] == 'X' && b2[1] == 'X' && c1[1] == 'X') {
    return 1;
  }

  if (a1[1] == 'O' && a2[1] == 'O' && a3[1] == 'O') {
    return 1;
  }
  if (b1[1] == 'O' && b2[1] == 'O' && b3[1] == 'O') {
    return 1;
  }
  if (c1[1] == 'O' && c2[1] == 'O' && c3[1] == 'O') {
    return 1;
  }
  if (a1[1] == 'O' && b1[1] == 'O' && c1[1] == 'O') {
    return 1;
  }
  if (a2[1] == 'O' && b2[1] == 'O' && c2[1] == 'O') {
    return 1;
  }
  if (a3[1] == 'O' && b3[1] == 'O' && c3[1] == 'O') {
    return 1;
  }
  if (a1[1] == 'O' && b2[1] == 'O' && c3[1] == 'O') {
    return 1;
  }
  if (a3[1] == 'O' && b2[1] == 'O' && c1[1] == 'O') {
    return 1;
  }
  if (a1[1] != ' ' && a2[1] != ' ' && a3[1] != ' ' && b1[1] != ' ' &&
      b2[1] != ' ' && b3[1] != ' ' && c1[1] != ' ' && c2[1] != ' ' &&
      c3[1] != ' ') {
    return 1;
  }

  return 0;
}

int draw(char a1[], char a2[], char a3[], char b1[], char b2[], char b3[],
         char c1[], char c2[], char c3[]) {
  if (a1[1] != ' ' && a2[1] != ' ' && a3[1] != ' ' && b1[1] != ' ' &&
      b2[1] != ' ' && b3[1] != ' ' && c1[1] != ' ' && c2[1] != ' ' &&
      c3[1] != ' ') {
    return 1;
  }
  return 0;
}

void chooser(char pole[], int *akthrac) {
  if (pole[1] == 'X' || pole[1] == 'O') {
    printf("Toto pole už bylo zvoleno!\n");
    sleep(1);
    if (*akthrac == 2) {
      *akthrac = 1;
    } else {
      *akthrac = 2;
    }
    return;
  }
  if (*akthrac == 2) {
    strcpy(pole, " X ");
    return;
  } else {
    strcpy(pole, " O ");
    return;
  }

  return;
}

void def_check(int *akthrac) {
  printf("Špatný vstup!\n");
  sleep(1);
  if (*akthrac == 2) {
    *akthrac = 1;
  } else {
    *akthrac = 2;
  }
  return;
}
