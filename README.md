# VUT PROJEKT - PIŠKVORKY V C
## AUTOŘI:
**Simon Veselý** - 271017<br>
**Vojtěch Šafář** - 270292
## O projektu:
1. Princip a funkce hry:
<img src="images/hlavni_menu.png" alt="Hlavní menu" width="600" height="350">

Struktura projektu:

1.

2. Linux/MacOS
<img src="images/struktura_linux:macos.png" alt="struktura-Linux/MacOS" width="200" height="300">

Výběr herních módů:

2. Jak hru spustit/verze hry pro Windows,Linux/MacOS<br>

Na Windows otevřeme project ve IDE Visual Studio 2022 a spustíme, jedná se o normální CMakeProject

Pro Linux/MacOS lze samostatně kompilovat main.c, a poté jej spustit v terminálu
```
gcc -Iinclude src/main.c lib/mylib.c lib/hxh.c -o bin/main
./bin/main
```
