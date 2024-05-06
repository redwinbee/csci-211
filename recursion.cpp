#include "recursion.h"

#include <iostream>

void Recursion::run()
{
    int num;
    std::cout << "enter a number to check if it is a power of 3: ";
    std::cin >> num;
    factor_of_three(num) ? std::cout << "true" : std::cout << "false";
}

bool Recursion::factor_of_three(const int num)
{
    if (num == 3) {
        return true;
    }

    if (num == 0) {
        return false;
    }

    factor_of_three(num / 3);
}


