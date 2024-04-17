#include "dynamic_memeory.h"

#include <iostream>

void reverse_arr(int* arr, int arr_size);
void print_arr(int* arr, int arr_size);

void DynamicMemory::run()
{
    int arr_size;
    std::cout << "plase enter the size of the array: ";
    std::cin >> arr_size;

    const auto arr = new int[arr_size];
    for(int i = 0; i < arr_size; i++) {
        int val;
        std::cout << "please enter int #" << (i + 1) << ": ";
        std::cin >> val;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        arr[i] = val;
    }

    print_arr(arr, arr_size);
    reverse_arr(arr, arr_size);
    print_arr(arr, arr_size);

    delete[] arr;
}

void reverse_arr(int* arr, const int arr_size)
{
    int* start = arr;
    int* end = (arr + arr_size - 1);
    while (start < end) {
        // make the swap
        const int temp = *(start);
        *(start) = *(end);
        *(end) = temp;

        // move the pointers
        start++;
        end--;
    }
}

void print_arr(int* arr, int arr_size)
{
    std::cout << "[ ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << ']' << std::endl;
}
