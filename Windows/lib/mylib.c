#include <stdio.h> // knihovna pro načítání vstupů a výstupů 
#include <stdlib.h> // knihovna pro systémové příkazy

// nadefinování ANSI znaků pro změnu barev v text
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

// funkce pro vyčištění obrazovky(konzolový příkaz 'clear')
void clearScreen() { system("cls"); }

// funkce pro výpis ASCII artu
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

// funkce pro zobrazení jednotlivých položek v hlavním menu
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

// funkce pro ukončení aplikace
void goodbye() {
  clearScreen();
  printf("Děkujeme za zahrání hry\n");
}
