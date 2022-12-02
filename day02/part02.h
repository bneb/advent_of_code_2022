#ifndef DAY02_PART02_H_
#define DAY02_PART02_H_

#include <iostream>
#include <map>

namespace part02
{

    namespace
    {
        // A function mapping the strategy to the played symbol.
        char OutcomeMap(char l,
                        char r,
                        std::map<char, char> defeat_map,
                        std::map<char, char> victory_map)
        {
            switch (r)
            {
            case 'X':
                return victory_map[l];
            case 'Y':
                return l;
            case 'Z':
                return defeat_map[l];
            default:
                throw("Unsupported outcome map char: ", r);
            }
        };
    }

    int64_t ScoreRound(char l, char r,
                       std::map<char, int> point_map,
                       std::map<char, char> defeat_map,
                       std::map<char, char> victory_map)
    {
        int64_t points = 0;
        r = OutcomeMap(l, r, defeat_map, victory_map);
        points += point_map.at(r);
        if (l == r)
            points += 3;
        else if (l == victory_map[r])
            points += 6;
        return points;
    }

} // namespace part02

#endif // DAY02_PART02_H_