#ifndef DAY03_PART01_H_
#define DAY03_PART01_H_

#include <set>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

namespace part01
{

    std::pair<std::set<char>, std::set<char>> GetRucksacks(std::string sack)
    {
        std::set<char> left(begin(sack), begin(sack) + sack.length() / 2);
        std::set<char> right(begin(sack) + sack.length() / 2, end(sack));
        return std::make_pair(left, right);
    }

    std::set<char> FindCommonElements(std::set<char> left, std::set<char> right)
    {
        std::set<char> common_elements;
        std::set_intersection(left.begin(), left.end(),
                              right.begin(), right.end(),
                              std::inserter(common_elements,
                                            common_elements.begin()));
        return common_elements;
    }

    int ScoreLetter(char c)
    {
        if (c <= 'Z')
            return c - 'A' + 1 + 26;
        return c - 'a' + 1;
    }

    int ScoreRucksack(std::string sack)
    {
        auto [left, right] = GetRucksacks(sack);
        std::set<char> common_elements = FindCommonElements(left, right);
        // Guaranteed to have a single element in the prompt.
        return ScoreLetter(*common_elements.begin());
    }

} // namespace part01

#endif // DAY03_PART01_H_