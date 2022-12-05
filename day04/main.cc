#include <iostream>
#include <string.h>

#include "part01.h"
#include "part02.h"
#include "util.h"

int main(int argc, char **argv)
{
    std::cout << "\\ Day04" << std::endl;

    std::string input_str;

    int64_t part1_points = 0;
    int64_t part2_points = 0;

    while (std::cin)
    {
        if (std::getline(std::cin, input_str))
        {
            auto [lPair, rPair] = util::ParseAssigmentStr(input_str);
            bool full_overlap = part01::DetectFullOverlap(
                lPair.first, lPair.second, rPair.first, rPair.second);

            if (full_overlap)
            {
                part1_points += full_overlap;
                part2_points += full_overlap;
            }
            else
            {
                part2_points += part02::DetectPartialOverlap(
                    lPair.first, lPair.second, rPair.first, rPair.second);
            }
        }
    }
    std::cout << " \\  Part01 --- Total points: " << part1_points << std::endl;
    std::cout << "  \\ Part02 --- Total points: " << part2_points << std::endl;
}