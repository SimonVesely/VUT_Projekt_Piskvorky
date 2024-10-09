#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen() { system("clear"); }

void welcome() {
  printf("Vyber si styl hry:\n1) Hráč x Hráč\n2) Hráč x AI\nQ) Odejít z "
         "programu\n");
}

void goodbye() {
  clearScreen();
  printf("Ďakujem za zahrání gamesky\n");
}

int main() {
  char choice = ' ';
  while (choice != 'q' && choice != 'Q') {
    clearScreen();
    welcome();
    scanf("%c", &choice);
    switch (choice) {
    case 1:
      break;
    case 2:
      break;
    case 'q':
      goodbye();
      break;
    case 'Q':
      goodbye();
      break;
    default:
      printf("Špatně vložený input\n");
      sleep(2);
      break;
    }
  }
  return 0;
}
