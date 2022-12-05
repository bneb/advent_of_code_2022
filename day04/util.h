#ifndef DAY04_UTIL_H_
#define DAY04_UTIL_H_

#include <utility>
#include <string>

namespace util
{
    std::pair<int, int> ParseRange(std::string s)
    {
        int delimiter_index = s.find("-");
        return {std::stoi(s.substr(0, delimiter_index)),
                std::stoi(s.substr(delimiter_index + 1, s.length()))};
    }

    std::pair<std::pair<int, int>, std::pair<int, int>> ParseAssigmentStr(std::string s)
    {
        int delimiter_index = s.find(",");
        return {ParseRange(s.substr(0, delimiter_index)),
                ParseRange(s.substr(delimiter_index + 1, s.length()))};
    }
} // namespace util

#endif // DAY04_UTIL_H_