#include <stdio.h>
#include <unistd.h> // čas
#include "mylib.h"

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
