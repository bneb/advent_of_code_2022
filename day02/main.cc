#include <iostream>
#include <string.h>

#include "part01.h"
#include "part02.h"

int main(int argc, char **argv)
{
    std::cout << "\\ Day02" << std::endl;

    std::string round_str;

    // A map of how many points correspond to playing each char.
    std::map<char, int> point_map = std::map<char, int>({{'A', 1}, {'B', 2}, {'C', 3}});
    // A map of strategy char to play char, i.e. 'X' and 'A' are both rock.
    std::map<char, char> strategy_map = std::map<char, char>({{'X', 'A'}, {'Y', 'B'}, {'Z', 'C'}});
    // A map of a played symbol to the symbol that it should defeat.
    std::map<char, char> victory_map = std::map<char, char>({{'B', 'A'}, {'A', 'C'}, {'C', 'B'}});
    // A map of a played symbol to the symbol that should should defeat it.
    std::map<char, char> defeat_map = std::map<char, char>({{'A', 'B'}, {'B', 'C'}, {'C', 'A'}});

    int64_t part1_points = 0;
    int64_t part2_points = 0;

    while (std::cin)
    {
        if (std::getline(std::cin, round_str))
        {
            char l = round_str.at(0);
            char r = round_str.at(2);
            part1_points += part01::ScoreRound(l, r, point_map, strategy_map, victory_map);
            part2_points += part02::ScoreRound(l, r, point_map, defeat_map, victory_map);
        }
    }
    std::cout << " \\  Part01 --- Total points: " << part1_points << std::endl;
    std::cout << "  \\ Part02 --- Total points: " << part2_points << std::endl;
}