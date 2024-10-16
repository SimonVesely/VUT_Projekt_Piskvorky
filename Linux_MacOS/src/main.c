#include "../include/hxh.h"
#include "../include/mylib.h"
#include <stdio.h>
#include <unistd.h> // čas

int main() {
  char choice[] = "";
  while (choice[0] != '5') {
    clearScreen();
    ascii();
    welcome();
    scanf("%s", choice);
    switch (choice[0]) {
    case '1':
      humanXhuman();
      break;
    case '2':
      printf("Work in progress\n");
      sleep(2);
      break;
    case '3':
      printf("Work in progress\n");
      sleep(2);
      break;
    case '4':
      printf("Work in progress\n");
      sleep(2);
      break;
    case '5':
      goodbye();
      break;
    default:
      printf("Špatně vložený input\n");
      sleep(2);
    }
  }
  return 0;
}
