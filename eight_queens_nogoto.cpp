#include "eight_queens_nogoto.h"

#include <iostream>

void EightQueensNoGoTo::run()
{
    int queens[8] = {};
    int col = 0;
    int solution_count = 0;
    queens[col] = 0;
    while (col != -1) {
        col++;
        if (col == 8) {
            print(queens, solution_count);
            col--;
        } else {
            queens[col] = -1;
        }
        while (queens[col] != 8) {
            queens[col]++;
            if (queens[col] == 8) {
                col--;
                if (col == -1) {
                    break;
                }
            } else if (ok(queens, col)) {
                break;
            }
        }
    }

    std::cout << '\n';
    std::cout << "no more solutions!\n";
}

bool EightQueensNoGoTo::ok(const int queens[], int col)
{
    // row test
    for (int i = 0; i < col; i++) {
        if (queens[i] == queens[col]) {
            return false;
        }
    }

    // up diagonal test
    for (int i = 0; i < col; i++) {
        if (col - i == queens[col] - queens[i]) {
            return false;
        }
    }

    // down diagonal test
    for (int i = 0; i < col; i++) {
        if ((queens[i] == queens[col]) || (col - i) == abs(queens[col] - queens[i])) {
            return false;
        }
    }

    return true;
}

void EightQueensNoGoTo::print(const int queens[], int& solution_count)
{
    printf("solution #%d:\n", solution_count++);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (queens[j] == i) {
                std::cout << 1 << ' ';
            } else {
                std::cout << 0 << ' ';
            }
        }
        std::cout << '\n';
    }
}
