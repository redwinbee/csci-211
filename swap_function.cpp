#include "swap_function.h"

#include <iostream>

void Swap::run()
{
    int x = 10, a = 10;
    int y = 20, b = 20;
    int* pa = &a;
    int* pb = &b;
    printf("before: [x: %d, y: %d]\n", x, y);
    printf("before: [a: %d, b: %d]\n", *(pa), *(pb));
    swap_using_ampersand(x, y);
    swap_using_direct_pointers(pa, pb);
    printf("after: [x: %d, y: %d]\n", x, y);
    printf("after: [a: %d, b: %d]\n", *(pa), *(pb));
}

// pass by reference
void Swap::swap_using_ampersand(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// de-sugared pass by reference using pointers directly
void Swap::swap_using_direct_pointers(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}