#include <iostream>
#include <string.h>

#include "part01.h"
#include "part02.h"

int main(int argc, char **argv)
{
    std::cout << "\\ Day03" << std::endl;

    std::string sack_str;
    part02::ElfGroupCoordinator egc;

    int64_t part1_points = 0;
    int64_t part2_points = 0;

    while (std::cin)
    {
        if (std::getline(std::cin, sack_str))
        {
            part1_points += part01::ScoreRucksack(sack_str);
            part2_points += egc.Coordinate(sack_str);
        }
    }
    std::cout << " \\  Part01 --- Total points: " << part1_points << std::endl;
    std::cout << "  \\ Part02 --- Total points: " << part2_points << std::endl;
}