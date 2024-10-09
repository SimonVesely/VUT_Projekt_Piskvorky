#include <stdio.h>
#include <stdlib.h> //systémové příkazy

void clearScreen() { system("clear"); }

void welcome() {
  printf("Vyber si styl hry:\n1) Hráč x Hráč\n2) Hráč x AI\nQ) Odejít z "
         "programu\n");
}

void goodbye() {
  clearScreen();
  printf("Ďakujem za zahrání gamesky\n");
}
