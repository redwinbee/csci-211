#pragma once

typedef double (*FUNC)(const double&);

constexpr double DELTA = 0.0001;

class Integration {
public:
    static void run();
    static double line(const double& x);
    static double square(const double& x);
    static double cube(const double& x);
    static double integrate(FUNC f, const double& a, const double& b);
};