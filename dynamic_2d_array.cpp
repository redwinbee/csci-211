#include "dynamic_2d_array.h"

#include <iostream>

void Dynamic2DArray::run()
{
    int arr_size;
    std::cout << "plase enter the size of the array: ";
    std::cin >> arr_size;

    // initialize the array
    int** arr = new int * [arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = new int[arr_size];
    }

    // populate the arrays
    int count = arr_size * arr_size;
    // this is how to fill the array in ascending order
    //
    // for (int i = arr_size - 1; i >= 0; i--) {
    //     for (int j = arr_size - 1; j >= 0; j--) {
    //         arr[j][i] = count--;
    //     }
    // }

    // fill the array in reverse order
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < arr_size; j++) {
            arr[j][i] = count--;
        }
    }

    // print the arrays
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < arr_size; j++) {
            std::cout << arr[j][i] << '\t';
        }
        std::cout << std::endl;
    }

    // free the memory
    for (int i = 0; i < arr_size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
