#include "eight_queens_fancy.h"

#include <iostream>
#include <string>

void EightQueensFancy::run()
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

bool EightQueensFancy::ok(const int queens[], int col)
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

void EightQueensFancy::print(const int queens[], int& solution_count)
{
    printf("solution #%d:\n", solution_count++);
    printf("1D array: ");
    std::cout << "[ ";
    for (int i = 0; i < 8; i++) {
        std::cout << queens[i] << ' ';
    }
    std::cout << ']' << std::endl;

    const std::string BOX = "\u2588";
    typedef std::string box[5][7];
    box black_box, white_box, *board[8][8];

    // initialize the white queen
    std::string black_queen[5][7] = {
        { BOX, BOX, BOX, BOX, BOX, BOX, BOX },
        { BOX, " ", BOX, " ", BOX, " ", BOX },
        { BOX, " ", " ", " ", " ", " ", BOX },
        { BOX, " ", " ", " ", " ", " ", BOX },
        { BOX, BOX, BOX, BOX, BOX, BOX, BOX },
    };

    // initialize the black queen
    std::string white_queen[5][7] = {
        { " ", " ", " ", " ", " ", " ", " " },
        { " ", BOX, " ", BOX, " ", BOX, " " },
        { " ", BOX, BOX, BOX, BOX, BOX, " " },
        { " ", BOX, BOX, BOX, BOX, BOX, " " },
        { " ", " ", " ", " ", " ", " ", " " },
    };

    // initialize the colour of the boxes (the squares on the chess board)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            black_box[i][j] = ' ';
            white_box[i][j] = BOX;
        }
    }

    // initialize the board itself, using the squares we just created
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                if (i == queens[j]) {
                    board[i][j] = &black_queen;
                } else {
                    board[i][j] = &white_box;
                }
            } else {
                if (i == queens[j]) {
                    board[i][j] = &white_queen;
                } else {
                    board[i][j] = &black_box;
                }
            }
        }
    }

    // print out the board
    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 5; k++) {
            std::cout << char(179);
            for (int j = 0; j < 8; j++) {
                for (int l = 0; l < 7; l++) {
                    std::cout << (*board[i][j])[k][l];
                }
            }
            std::cout << char(179) << '\n';
        }
    }
}
