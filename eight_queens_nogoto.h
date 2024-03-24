#pragma once

class EightQueensNoGoTo {
public:
    static void run();
    static bool ok(const int queens[], int col);
    static void print(const int queens[], int &solution_count);
};
