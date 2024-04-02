#include "eight_numbers.h"

#include <iostream>

void EightNumbers::run()
{
    int cross[8] = {};
    eightNumbers(cross, 0);
}

bool EightNumbers::ok(const int cross[], int cap)
{
    /*
     * adjacent blocks mapping - each row contains a list of indices
     * identifying other blocks that could cause conflicts if not checked
     * before assigning a number to that row. the sentinel value (stopping
     * value) after each element in the list is -1.
     */
    int checklist[8][5] = {
        { -1 },
        { 0, -1 },
        { 0, -1 },
        { 0, 1, 2, -1 },
        { 0, 1, 3, -1 },
        { 1, 4, -1 },
        { 2, 3, 4, -1 },
        { 3, 4, 5, 6, -1 },
    };

    // row test
    for (int i = 0; i < cap; i++) {
        if (cross[i] == cross[cap]) {
            return false;
        }
    }

    // check the current column we're in to see if there will be conflicts
    int i = 0;
    while (checklist[cap][i] != -1) {
        if (abs(cross[checklist[cap][i]] - cross[cap]) == 1) {
            return false;
        }

        i++;
    }

    return true;
}

void EightNumbers::eightNumbers(int cross[], int cap)
{ // NOLINT (misc-no-recursion)
    if (cap == 8) {
        print(cross);
        return;
    }

    for (cross[cap] = 1; cross[cap] <= 8; ++cross[cap]) {
        if (ok(cross, cap)) {
            eightNumbers(cross, cap + 1);
        }
    }
}

void EightNumbers::print(int cross[])
{
    static int count = 0;
    std::cout << "solution #" << ++count << '\n';
    std::cout << ' ' << cross[0] << cross[1] << '\n';
    std::cout << cross[2] << cross[3] << cross[4] << cross[5] << '\n';
    std::cout << ' ' << cross[6] << cross[7] << '\n';
}