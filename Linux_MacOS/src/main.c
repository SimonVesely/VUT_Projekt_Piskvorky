#include "../include/hxh.h" // knihovna pro mod hráč x hráč
#include "../include/hxai.h" // knihovna pro mod hráč x ai
#include "../include/mylib.h" // knihovna s custom scripty, které by se opakovali v částech kódu
#include "../include/leaderboard.h" // knihovna vypisující data do leaderboardu
#include <stdio.h> // knihovna pro načítání vstupů a výstupů
#include <unistd.h> // knihovna pro čas(sleep)

int main() {
  char choice[256];

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
      humanXai();
      break;

    case '3':
      navod();
      break;

    case '4':
      reader_lb();
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
