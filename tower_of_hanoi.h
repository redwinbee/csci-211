#pragma once

#include <vector>

class TowerOfHanoi {
public:
    static void run();

    /**
     * calculates the next "from" tower. this is done by checking for the closest tower that
     * we can place the top of the "to" tower on. the modulo 3 ensures that we are only ever
     * dealing with the 3 towers since we will always have numbers 1, 2, or 3.
     *
     * @param towers the current towers configuration
     * @param to the current "to" tower
     * @param from the current "from" tower
     */
    static void calculate_from(const std::vector<int> towers[], const int& to, int& from);

    /**
     * calculate the next "to" tower. this is done by checking for the closest tower that the
     * candidate can be placed on top of. if the number of disks is odd then the closest tower
     * is [(from + 1) % 3] and [(from + 2) % 3] if it's an even number of disks.
     *
     * @param towers the current towers configuration
     * @param candidate the current candidate disk
     * @param to the current "to" tower
     * @param from the current "from" tower
     */
    static void calculate_to(const std::vector<int> towers[], const int& candidate, int& to, const int& from);
};