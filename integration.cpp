#include "integration.h"

#include <iostream>

void Integration::run()
{
    std::cout << "the integral of f(x) = x from 1 to 5 is: " << integrate(line, 1, 5) << std::endl;
    std::cout << "the integral of f(x) = x^2 from 1 to 5 is: " << integrate(square, 1, 5) << std::endl;
    std::cout << "the integral of f(x) = x^3 from 1 to 5 is: " << integrate(cube, 1, 5) << std::endl;
}

double Integration::line(const double& x)
{
    return x;
}

double Integration::square(const double& x)
{
    return x * x;
}

double Integration::cube(const double& x)
{
    return x * x * x;
}

double Integration::integrate(const FUNC f, const double& a, const double& b)
{
    double sum = 0;
    double x = a;
    while (x < b) {
        sum += f(x) * DELTA;
        x += DELTA;
    }

    return sum;
}
