#include "vectors.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

void Vectors::run()
{
    int num;
    std::cin >> num;
    // clang-format off
    std::vector<std::vector<int> > test_scores;
    // clang-format on

    // read all the scores
    for (int i = 0; i < num; ++i) {
        int n;
        std::cin >> n;
        std::vector<int> scores(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> scores[j]; // read the scores
        }

        test_scores.push_back(scores); // push all these scores to the container vector
    }

    // output the results
    for (const std::vector<int>& results : test_scores) {
        // get the sum of all the scores
        double sum = 0;
        int n = results.size();
        for (int score : results) {
            sum += score;
        }

        // calculate the average and number of scores that were above average
        double avg = sum / n;
        int above_avg_count = 0;
        for (int score : results) {
            if (score > avg) {
                above_avg_count++;
            }
        }

        double above_avg_ratio = static_cast<double>(above_avg_count) / n * 100;
        std::cout << std::fixed << above_avg_ratio << "%" << std::endl;
    }
}
