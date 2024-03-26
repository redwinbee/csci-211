#include <iostream>
#include "pointers.h"

void Pointers::run() {
    // pointers can be used to change values of the variable
    // that they are pointing to
    int x = 10;
    int y = 20;
    printf("before: (x: %d, y: %d)\n", x, y);
    int *xp = &x;
    *xp = 45;
    printf("after: (x: %d, y: %d)\n", x, y);

    /*
     * arrays are index using pointers and pointer arithmetic. when
     * we say something like arr[i] what we are really saying is *(arr + i)
     * which is just going to the pointer at the start of the array_1d, and going
     * down by an offset of i, then dereference that pointer to get the value
     */
    int array_1d[3] = {1, 2, 3};
    std::cout << "array_1d: ";
    for (int i = 0; i < 3; i++) {
        std::cout << *(array_1d + i) << ' ';   // same as array_1d[i]
        if (i == 2) {
            std::cout << std::endl;
        }
    }

    /*
     * since arrays are just contiguous blocks of memory accessed by a pointer, the
     * same logic applies when dealing with 2D arrays. similar to how we access all the
     * elements of a 1D array_1d in a loop with:
     *                  array_1d[i]    === *(array_1d + i)
     * we can also do the same for 2D arrays:
     *                  array_1d[i][j] === *(*(array_1d + i) + j)
     */
    int array_2d[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };
    std::cout << "array_2d:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << *(*(array_2d + i) + j) << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "array_2d[1][1]: " << *(*(array_2d + 1) + 1) << std::endl;
    // we can also access the first element of each embedded array with double de-referencing
    std::cout << "array_2d[1][0]: " << **(array_2d + 1);
}