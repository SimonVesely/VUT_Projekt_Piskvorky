# VUT PROJEKT - PIŠKVORKY V C
## AUTOŘI:
**Simon Veselý** - 271017<br>
**Vojtěch Šafář** - 270292
## O projektu:
1. Princip a funkce hry:
<img src="images/hlavni_menu.png" alt="Hlavní menu" width="600" height="350">

**Struktura projektu:**

1. Windows
...



2. Linux/MacOS
<img src="images/struktura_linux:macos.png" alt="struktura-Linux/MacOS" width="200" height="300">


**Spuštění hry:**

1. Windows

Na Windows otevřeme project ve IDE Visual Studio 2022 a spustíme, jedná se o normální CMakeProject


2. Linux/MacOS
   
Pro Linux/MacOS lze samostatně kompilovat main.c, a poté jej spustit v terminálu
```
gcc -Iinclude src/main.c lib/mylib.c lib/hxh.c -o bin/main
./bin/main
```
**Výběr herních módů:**

1. Jakmile hru spustíme, vyskočí na nás okno s výběrem stylu hry

2. K dispozici jsou 2 herní režimy: Hráč proti hráči
                                    Hráč proti AI

3. Také je zde možnost návodu, kde se nachází kompletní informace o hře Piškvorky

4. Jako čtvrtá možnost je zde vypnutí hry


**Styly hry:**

1. Jako první styl hry je zde Hráč proti Hráči
   
   Uživatel si na začátku bude muset zvolit jméno a poté se mu otevře hra

   Tento styl hry funguje pomocí loopu s proměnnou if, else
<br>

3. Jako druhý styl hry je zde Hráč proti AI
   ...
   ...
   ...

4. Návod

   (Zde bude ctrlC ctrlV z té samotne appky)

6. Vypnutí hry

   Hra se po zvolení této možnosti vypne pomocí funkce: goodbye

