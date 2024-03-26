#include <iostream>
#include "stable_marriage.h"

void StableMarriage::run() {
    int pairs[3];
    int col = 0;
    pairs[col] = 0;
    while (col != -1) {
        col++;
        if (col == 3) {
            print(pairs);
            col--;
        }
        else {
            pairs[col] = -1;
        }
        while (pairs[col] != 3) {
            pairs[col]++;
            if (pairs[col] == 3) {
                col--;
                if (col == -1) {
                    break;
                }
            }
            else if (ok(pairs, col)) {
                break;
            }
        }
    }

    std::cout << '\n';
    std::cout << "no more solutions!\n";
}

bool StableMarriage::ok(const int *pairs, int col) {
    const int mp[3][3] = {
            {0, 2, 1},
            {0, 2, 1},
            {1, 2, 0},
    };

    const int wp[3][3] = {
            {2, 1, 0},
            {0, 1, 2},
            {2, 0, 1},
    };

    // legend
    /*
     * current man: i
     * current woman: pairs[i]
     * new man: col
     * new woman: pairs[col]
     */

    // check if the new woman has already been assigned to a man
    for (int i = 0; i < col; i++) {
        if (pairs[i] == pairs[col]) {
            return false;
        }
    }

    /*
     * check if the current man prefers the new woman to his partner and if the
     * new woman prefers the current man to her partner
     */
    for (int i = 0; i < col; i++) {
        if (mp[i][pairs[col]] < mp[i][pairs[i]] && wp[pairs[col]][i] < wp[pairs[col]][col]) {
            return false;
        }
    }

    /*
     * check if the new man prefers the current woman to his partner and if the current
     * woman prefers the new man to her partner
     */
    for (int i = 0; i < col; i++) {
        if (mp[col][pairs[i]] < mp[col][pairs[col]] && wp[pairs[i]][col] < wp[pairs[i]][i]) {
            return false;
        }
    }

    return true;
}

void StableMarriage::print(const int *pairs) {
    static int solution_count = 0;
    std::cout << "solution #" << solution_count++ << '\n';
    std::cout << "man\twoman" << '\n';
    for (int i = 0; i < 3; i++) {
        std::cout << i << '\t' << pairs[i] << '\n';
    }
    std::cout << std::endl;
}