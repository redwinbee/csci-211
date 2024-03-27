#pragma once

class Swap {
public:
    static void run();

private:
    static void swap_using_ampersand(int &x, int &y);
    static void swap_using_direct_pointers(int *a, int *b);
};