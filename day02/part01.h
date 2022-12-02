#ifndef DAY02_PART01_H_
#define DAY02_PART01_H_

#include <map>

namespace part01
{

    int64_t ScoreRound(char l, char r,
                       std::map<char, int> point_map,
                       std::map<char, char> strategy_map,
                       std::map<char, char> victory_map)
    {
        int64_t points = 0;
        char played_r = strategy_map.at(r);
        points += point_map.at(played_r);
        if (l == played_r)
            points += 3;
        else if (l == victory_map[played_r])
            points += 6;
        return points;
    }

} // namespace part01

#endif // DAY02_PART01_H_