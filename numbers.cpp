#include "numbers.h"
#include <iostream>
#include <cmath>

void Numbers::run()
{
    int a, b;
    std::cout << "please enter two numbers to calculate their lcm: ";
    std::cin >> a;
    std::cin >> b;

    std::cout << "lcm: " << lcm(a, b) << std::endl;
}

int Numbers::gcd(int a, int b)
{
    while (b != 0) {
        const int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}


int Numbers::lcm(const int a, const int b)
{
    return std::abs(a * b) / gcd(a, b);
}
