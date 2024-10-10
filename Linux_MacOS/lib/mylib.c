#include <stdio.h>
#include <stdlib.h> //systémové příkazy

void clearScreen() { system("clear"); }

void welcome() {
  printf("┌─────────────────────────┐\n"
         "│┏━┓╻┏━┓╻┏ ╻ ╻┏━┓┏━┓╻┏ ╻ ╻│\n"
         "│┣━┛┃┗━┓┣┻┓┃┏┛┃ ┃┣┳┛┣┻┓┗┳┛│\n"
         "│╹  ╹┗━┛╹ ╹┗┛ ┗━┛╹┗╸╹ ╹ ╹ │\n"
         "└─────────────────────────┘"
         "\n");
  printf(
      "Vyber si styl hry:\n1) Hráč x Hráč\n2) Hráč x AI\n3) Návod\n4) Odejít z "
      "programu\n");
}

void goodbye() {
  clearScreen();
  printf("Ďakujem za zahrání gamesky\n");
}
