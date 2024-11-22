#include <stdio.h> // knihovna pro načítání vstupů a výstupů 
#include <stdlib.h> // knihovna pro systémové příkazy

// nadefinování ANSI znaků pro změnu barev v text
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW  "\x1b[33m"

// funkce pro vyčištění obrazovky(konzolový příkaz 'clear')
void clearScreen() { system("clear"); }

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

// funkce pro vypsání návodu
void navod(){
  char input[256];
  while (input[0] != 'q' && input[0] != 'Q'){
    printf("NÁVOD:\n\n\nHrací pole:\n"
      "        Y\n"
      "        ^\n"
      "        |   ---------------\n"
      "        1  |"RED" X "RESET"| . |"YELLOW" O "RESET"| . |\n"
      "        |  |---|---|---|---|\n"
      "        2  | . |"RED" X "RESET"| O | . |\n"
      "        |  |---|---|---|---|\n"
      "        3  | . | . |"RED" X "RESET"| . |\n"
      "        |  |---|---|---|---|\n"
      "        4  | . | . | . | . |\n"
      "        |   ---------------\n"
      "        *----1---2---3---4----->X\n\n"GREEN
      "1."RESET" Hráč si vybírá pole podle os, nejprve osu Y, poté osu X\n"
      "                                      např. pro vyznačené "YELLOW"O"RESET" žlutě: 13 - (Hodnota YX)\n\n"GREEN
      "2."RESET" Hráč vyhrává pokud se mu podaří spojit 3 body, buď horizontálně, vertikálně nebo diagonálně\n"
      "                                      např. pro vyznačené červené body "RED"X"RESET"\n\n"GREEN
      "3."RESET" Pokud nikdo nevyhraje, můžete zvolit restart hry nebo odchod do hlavního menu\n\n\n"
      "Q = Zpět do hlavního menu\n");
    scanf("%s", input);
  }
  return ;
}
