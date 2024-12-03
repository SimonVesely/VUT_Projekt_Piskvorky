#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int checker(char hracipole[9][9], int velikostPole, char symbol) {
  if (velikostPole <= 4) {
    for (int row = 0; row < velikostPole; row++) {
      for (int col = 0; col <= velikostPole - 3; col++) {
        if (hracipole[row][col] == symbol &&
            hracipole[row][col + 1] == symbol &&
            hracipole[row][col + 2] == symbol) {
          return 1;
        }
      }
    }

    // Vertical check
    for (int col = 0; col < velikostPole; col++) {
      for (int row = 0; row <= velikostPole - 3; row++) {
        if (hracipole[row][col] == symbol &&
            hracipole[row + 1][col] == symbol &&
            hracipole[row + 2][col] == symbol) {
          return 1;
        }
      }
    }

    // Diagonal check
    for (int row = 0; row <= velikostPole - 3; row++) {
      for (int col = 0; col <= velikostPole - 3; col++) {
        if (hracipole[row][col] == symbol &&
            hracipole[row + 1][col + 1] == symbol &&
            hracipole[row + 2][col + 2] == symbol) {
          return 1;
        }
      }
    }

    for (int row = 0; row <= velikostPole - 3; row++) {
      for (int col = 2; col < velikostPole; col++) {
        if (hracipole[row][col] == symbol &&
            hracipole[row + 1][col - 1] == symbol &&
            hracipole[row + 2][col - 2] == symbol) {
          return 1;
        }
      }
    }
  } else {
    for (int row = 0; row < velikostPole; row++) {
      for (int col = 0; col <= velikostPole - 4; col++) {
        if (hracipole[row][col] == symbol &&
            hracipole[row][col + 1] == symbol &&
            hracipole[row][col + 2] == symbol &&
            hracipole[row][col + 3] == symbol) {
          return 1;
        }
      }
    }

    // Vertical check
    for (int col = 0; col < velikostPole; col++) {
      for (int row = 0; row <= velikostPole - 4; row++) {
        if (hracipole[row][col] == symbol &&
            hracipole[row + 1][col] == symbol &&
            hracipole[row + 2][col] == symbol &&
            hracipole[row + 3][col] == symbol) {
          return 1;
        }
      }
    }

    // Diagonal check
    for (int row = 0; row <= velikostPole - 4; row++) {
      for (int col = 0; col <= velikostPole - 4; col++) {
        if (hracipole[row][col] == symbol &&
            hracipole[row + 1][col + 1] == symbol &&
            hracipole[row + 2][col + 2] == symbol &&
            hracipole[row + 3][col + 3] == symbol) {
          return 1;
        }
      }
    }

    // Diagonal check
    for (int row = 0; row <= velikostPole - 3; row++) {
      for (int col = 2; col < velikostPole; col++) {
        if (hracipole[row][col] == symbol &&
            hracipole[row + 1][col - 1] == symbol &&
            hracipole[row + 2][col - 2] == symbol) {
          return 1;
        }
      }
    }
  }

  // No winner found
  return 0;
}

void aichooser(char hraciPole[9][9], int velikostPole, char result[3]) {
  int x, y;
  int dx[] = {0, 0, -1,
              1}; // Directions for adjacent cells (up, down, left, right)
  int dy[] = {-1, 1, 0, 0};

  srand(time(NULL));

  while (1) {
    // Find random position with 'X'
    x = rand() % velikostPole;
    y = rand() % velikostPole;

    if (hraciPole[x][y] == 'X') {
      // Check adjacent cells for '.'
      int validMoves[4][2]; // Array to store valid moves
      int validCount = 0;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < velikostPole && ny >= 0 && ny < velikostPole &&
            hraciPole[nx][ny] == '.') {
          validMoves[validCount][0] = nx;
          validMoves[validCount][1] = ny;
          validCount++;
        }
      }

      // If we have valid adjacent empty cells, choose one randomly
      if (validCount > 0) {
        int choice = rand() % validCount;
        int chosenX = validMoves[choice][0];
        int chosenY = validMoves[choice][1];

        // Store the result as a string in the format "xy"
        result[0] = '0' + chosenX;
        result[1] = '0' + chosenY;
        result[2] = '\0'; // Null-terminate the string
        return;
      }
    }
  }
}
