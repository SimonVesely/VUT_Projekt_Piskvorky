#include "../include/hxh.h"
#include "../include/mylib.h"
#include <stdio.h>
#include <unistd.h> // čas

int main() {
  char choice[] = "";
  while (choice[0] != 'q' && choice[0] != 'Q') {
    clearScreen();
    welcome();
    scanf("%s", choice);
    switch (choice[0]) {
    case '1':
      humanXhuman();
      break;
    case '2':
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
    }
  }
  return 0;
}
