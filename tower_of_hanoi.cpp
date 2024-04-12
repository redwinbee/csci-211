#include "tower_of_hanoi.h"

#include <iostream>
#include <vector>

void TowerOfHanoi::run()
{
    /*
     * get the number of rings that will be used and flush the input buffer. we don't
     * technically have to flush out the trailing chars but it's important to remember
     * for future use when working with std::cin.
     */
    int disks;
    std::cout << "enter the number of disks to use: ";
    std::cin >> disks;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    /*
     * setup the towers. we have to place the largest disks (biggest number) at the bottom of
     * every tower so that we have something to compare to later on when we check if a disk
     * can go on an "empty" tower.
     */
    std::vector<int> towers[3];
    for (int i = disks + 1; i > 0; i--) {
        towers[0].push_back(i);
    }
    towers[1].push_back(disks + 1);
    towers[2].push_back(disks + 1);

    /*
     * with the towers setup we can make the moves. if we have the number of disks to be
     * moved defined as n, then it will take exactly (2^n - 1) moves to move all disks
     * to another tower.
     */
    int from = 0;
    int to = 1;
    for (int i = 0; i <= (2 ^ disks + 1); i++) {
        calculate_from(towers, to, from);
        int candidate = towers[from].back();
        calculate_to(towers, candidate, to, from);
        towers[to].push_back(candidate);
        towers[from].pop_back();
        std::cout << "move number #" << (i + 1) << ": transfer ring #" << candidate
        << " from tower " << static_cast<char>(from + 'A') << " to tower " << static_cast<char>(to + 'A') << std::endl;
    }

}

void TowerOfHanoi::calculate_from(const std::vector<int> towers[], const int& to, int& from)
{
    if (towers[(to + 1) % 3].back() > towers[(to + 2) % 3].back()) {
        from = (to + 2) % 3;
    } else {
        from = (to + 1) % 3;
    }
}

void TowerOfHanoi::calculate_to(const std::vector<int> towers[], const int& candidate, int& to, const int& from)
{
    if (candidate > towers[(from + 1) % 3].back()) {
        to = (from + 2) % 3;
    } else {
        to = (from + 1) % 3;
    }
}

