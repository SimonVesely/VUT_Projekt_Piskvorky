#include <stdio.h>
#include <stdlib.h> //systémové příkazy
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void clearScreen() { system("clear"); }

void ascii(){
  printf("┌───────────────────────────────────┐\n"
         "│"RED"▌ ▌"RESET" ▛▀▖▗    ▌           ▌     "BLUE" ▞▀▀▖"RESET"│\n"
         "│"RED"▝▞ "RESET" ▙▄▘▄ ▞▀▘▌▗▘▌ ▌▞▀▖▙▀▖▌▗▘▌ ▌"BLUE" ▌  ▌"RESET"│\n"
         "│"RED"▞▝▖"RESET" ▌  ▐ ▝▀▖▛▚ ▐▐ ▌ ▌▌  ▛▚ ▚▄▌"BLUE" ▌  ▌"RESET"│\n"
         "│"RED"▘ ▘"RESET" ▘  ▀▘▀▀ ▘ ▘ ▘ ▝▀ ▘  ▘ ▘▗▄▘"BLUE" ▝▀▀ "RESET"│\n"
         "└───────────────────────────────────┘"
"\n");
  return;
}

void welcome() {
  /*printf("┌─────────────────────────┐\n"
         "│┏━┓╻┏━┓╻┏ ╻ ╻┏━┓┏━┓╻┏ ╻ ╻│\n"
         "│┣━┛┃┗━┓┣┻┓┃┏┛┃ ┃┣┳┛┣┻┓┗┳┛│\n"
         "│╹  ╹┗━┛╹ ╹┗┛ ┗━┛╹┗╸╹ ╹ ╹ │\n"
         "└─────────────────────────┘"
         "\n");*/
    printf(
      "Výběr stylů hry:\n1) Hráč x Hráč\n2) Hráč x AI\n3) Návod\n4) Leaderboard\n5) Odejít z "
      "programu\n\n\nZvolte váš výběr: ");
}

void goodbye() {
  clearScreen();
  printf("Ďakujem za zahrání gamesky\n");
}
