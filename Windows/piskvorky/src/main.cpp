#include "../include/hxh.h" // knihovna pro mod hráè x hráè
#include "../include/mylib.h" // knihovna s custom scripty, které by se opakovali v èástech kódu
#include "../include/leaderboard.h" // knihovna vypisující data do leaderboardu
#include <stdio.h> // knihovna pro naèítání vstupù a výstupù
#include <windows.h> // knihovna pro èas(sleep)

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
            printf("Work in progress\n");
            Sleep(2000);
            break;

        case '3':
            printf("Work in progress\n");
            Sleep(2000);
            break;

        case '4':
            reader_lb();
            break;

        case '5':
            goodbye();
            break;

        default:
            printf("Špatnì vložený input\n");
            Sleep(2000);
        }
    }

    return 0;
}
