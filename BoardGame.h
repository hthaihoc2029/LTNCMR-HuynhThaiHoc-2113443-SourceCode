#ifndef BOARD_H
#define BOARD_H

#include "Chip.h"

const int MAX_COLUMN = 7;

class BoardGame {
   private:
    static int numOfCol[MAX_COLUMN];
    Chip chips[ROWS][COLUMNS];

   public:
    BoardGame() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                chips[i][j].setColor(BLANK);
            }
        }
    }

    string toString() {
        string str, modifiedStr = "";

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                stringstream stream;
                stream << (char)chips[i][j].getColor();
                str = stream.str();

                modifiedStr += str + " ";
                str = "";
                if (j == COLUMNS - 1) {
                    modifiedStr += "\n";
                }
            }
        }

        return modifiedStr;
    }
    int putChipDown(Chip drop, int slot) {
        if (slot < 1 || slot > 7) return 0;
        if (numOfCol[slot - 1] < 0) {
            return 0;
        } else {
            chips[numOfCol[slot - 1]][slot - 1] = drop;
            numOfCol[slot - 1]--;
            return 1;
        }
        return 0;
    }

    int checkWin() {
        // Check for no winner case
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (chips[i][j].getColor() != 'X') {
                    count++;
                    if (count == TOTAL_SPACES) {
                        clearCol();
                        return 0;
                    }
                }
            }
        }

        // Determine the Winner
        const int DIRECTIONS = 4;
        int dx[DIRECTIONS] = {1, 0, 1, 1};
        int dy[DIRECTIONS] = {0, 1, 1, -1};

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                for (int d = 0; d < DIRECTIONS; d++) {
                    int colorSum = 0;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + k * dx[d];
                        int nj = j + k * dy[d];
                        if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLUMNS) {
                            colorSum += chips[ni][nj].getColor();
                        }
                    }
                    if (colorSum == RED_TOTAL) {
                        clearCol();
                        return 1;
                    }
                    if (colorSum == GOLD_TOTAL) {
                        clearCol();
                        return 2;
                    }
                }
            }
        }

        return -1;
    }

    void clearCol() {
        for (int i = 0; i < MAX_COLUMN; i++) {
            numOfCol[i] = 5;
        }
    }
};

#endif