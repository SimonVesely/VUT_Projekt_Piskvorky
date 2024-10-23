#include <stdio.h>
#include <string.h>
#include <unistd.h>

int checker(char hracipole[9][9], int velikostPole, char symbol) {
  for (int row = 0; row < velikostPole; row++) {
        for (int col = 0; col <= velikostPole - 3; col++) {
            if (hracipole[row][col] == symbol && 
                hracipole[row][col + 1] == symbol && 
                hracipole[row][col + 2] == symbol) {
                return 1; // Found a match
            }
        }
    }

    // Vertical check
    for (int col = 0; col < velikostPole; col++) {
        for (int row = 0; row <= velikostPole - 3; row++) {
            if (hracipole[row][col] == symbol && 
                hracipole[row + 1][col] == symbol && 
                hracipole[row + 2][col] == symbol) {
                return 1; // Found a match
            }
        }
    }

    // Diagonal check (top-left to bottom-right)
    for (int row = 0; row <= velikostPole - 3; row++) {
        for (int col = 0; col <= velikostPole - 3; col++) {
            if (hracipole[row][col] == symbol && 
                hracipole[row + 1][col + 1] == symbol && 
                hracipole[row + 2][col + 2] == symbol) {
                return 1; // Found a match
            }
        }
    }

    // Diagonal check (top-right to bottom-left)
    for (int row = 0; row <= velikostPole - 3; row++) {
        for (int col = 2; col < velikostPole; col++) {
            if (hracipole[row][col] == symbol && 
                hracipole[row + 1][col - 1] == symbol && 
                hracipole[row + 2][col - 2] == symbol) {
                return 1; // Found a match
            }
        }
    }

    // No winner found
    return 0;
}
