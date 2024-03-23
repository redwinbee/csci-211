#include <iostream>

int g_solution_count = 0;

int main() {
    int board[8][8] = {};
    int row = 0;
    int col = 0;
    board[row][col] = 1;
    nextCol:
        if (++col == 8) goto print;
        row = -1;   // go to the "top" of the column
    nextRow:
        if (++row == 8) goto backtrack;

        // row test
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                goto nextRow;
            }
        }

        // diagonal test
        // we keep going up the diagonal while we still can. the condition check
        // ensures we don't "fall off" the board
        for (int i = 1; ((row - i) >= 0 && (col - i) >= 0); i++) {
            if (board[row - i][col - i] == 1) {
                goto nextRow;
            }
        }

        // down diagonal test
        // just like the diagonal test. but now we check down and to the left to see
        // if we can place a queen here
        for (int i = 1; ((row + i) <= 7 && (col - i) >= 0); i++) {
            if (board[row + i][col - i] == 1) {
                goto nextRow;
            }
        }

        // no issues so we place a queen here
        board[row][col] = 1;

        // go to the next column
        goto nextCol;
    backtrack:
        if (--col == -1) {
            std::cout << "no more solutions!\n";
            return 0;
        }

        row = 0;
        while (board[row][col] != 1) {
            row++;
        }

        board[row][col] = 0;
        goto nextRow;
    print:
        printf("solution #%d:\n", g_solution_count++);
        for (auto &i: board) {
            for (int j: i) {
                std::cout << j << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        goto backtrack;
}