#include "swap_arrays_function.h"

#include <iostream>

void SwapArray::run()
{
    int x[SIZE] = { 1, 2, 3, 4, 5 };
    int y[SIZE] = { 9, 8, 7, 6, 5 };
    std::cout << "before" << std::endl;
    std::cout << "x: ";
    print(x, SIZE);
    std::cout << "y: ";
    print(y, SIZE);

    swap(x, y, SIZE);

    std::cout << "after" << std::endl;
    std::cout << "x: ";
    print(x, SIZE);
    std::cout << "y: ";
    print(y, SIZE);
}

void SwapArray::swap(int* x, int* y, int size)
{
    for (int i = 0; i < SIZE; i++) {
        int temp = *(x + i);
        *(x + i) = *(y + i);
        *(y + i) = temp;
    }
}

void SwapArray::print(int* x, int size)
{
    std::cout << "[ ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(x + i) << ' ';
    }
    std::cout << ']' << std::endl;
}
