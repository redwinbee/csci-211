#include <cmath>
#include <iostream>
#include "eight_queens_1d.h"

void EightQueens1D::run() {
    int queens[8] = {0};
    int col = 0;
    int solution_count = 0;
    nextCol:
        if (++col == 8) goto print;
        queens[col] = -1;   // start at the "top" of the column
    nextRow:
        queens[col]++;
        if (queens[col] == 8) goto backtrack;

        // row test
        for (int i = 0; i < col; i++) {
            if (queens[i] == queens[col]) {
                goto nextRow;
            }
        }

        // up diagonal test
        for (int i = 0; i < col; i++) {
            if (col - i == queens[col] - queens[i]) {
                goto nextRow;
            }
        }

        // down diagonal test
        for (int i = 0; i < col; i++) {
            if (queens[i] == queens[col] || (col - i) == abs(queens[col] - queens[i])) {
                goto nextRow;
            }
        }

        goto nextCol;   // we just need to go to the next column since the queen is already placed
    backtrack:
        if (--col == -1) {
            std::cout << "no more solutions!\n";
            return;
        }

        goto nextRow;
    print:
        printf("solution #%d:\n", solution_count++);
        std::cout << "array: ";
        print(queens);
        for (int i = 0; i < 8; i++) {
            for (int queen : queens) {
                if (queen == i) {
                    std::cout << 1 << ' ';
                } else {
                    std::cout << 0 << ' ';
                }
            }
            std::cout << '\n';
        }

        std::cout << std::endl;

        goto backtrack;
}

void EightQueens1D::print(const int *arr) {
    std::cout << "[ ";
    for (int i = 0; i < 8; i++) {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << "]\n";
}