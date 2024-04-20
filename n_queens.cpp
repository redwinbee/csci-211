#include "n_queens.h"

#include <iostream>

void NQueens::run()
{
    int num_queens;
    std::cout << "please enter the number of queens to evaluate the solutions for: ";
    std::cin >> num_queens;

    for (int i = 1; i <= num_queens; i++) {
        std::cout << "there are " << queens(i) << " solution(s) to the " << i << " queen(s) problem." << std::endl;
    }
}

int NQueens::queens(const int num_queens)
{
    const auto q = new int[num_queens] {};
    int solution_count = 0;
    int col = 0;
    q[col] = 0;
    while (col != -1) {
        col++;
        if (col == num_queens) {
            solution_count++;
            col--;
        }
        else {
            q[col] = -1;
        }
        while (q[col] != num_queens) {
            q[col]++;
            if (q[col] == num_queens) {
                col--;
                if (col == -1) {
                    break;
                }
            } else if (ok(q, col)) {
                break;
            }
        }
    }

    delete[] q;
    return solution_count;
}

bool NQueens::ok(int q[], const int col)
{
    // row test
    for (int i = 0; i < col; i++) {
        if (q[i] == q[col]) {
            return false;
        }
    }

    // up diagonal test
    for (int i = 0; i < col; i++) {
        if (col - i == q[col] - q[i]) {
            return false;
        }
    }

    // down diagonal test
    for (int i = 0; i < col; i++) {
        if (q[i] == q[col] || col - i == abs(q[col] - q[i])) {
            return false;
        }
    }

    return true;
}