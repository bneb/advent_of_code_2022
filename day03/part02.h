#ifndef DAY03_PART02_H_
#define DAY03_PART02_H_

#include <iostream>
#include <map>

#include "part01.h"

namespace part02
{
    class ElfGroupCoordinator
    {
    public:
        ElfGroupCoordinator(const ElfGroupCoordinator &) = delete;
        ElfGroupCoordinator &operator=(const ElfGroupCoordinator &) = delete;
        ElfGroupCoordinator() { i_ = 0; }

        // Update the group
        int Coordinate(std::string sack)
        {
            sacks_[i_] = std::set<char>(begin(sack), end(sack));
            if (++i_ == 3)
            {
                i_ = 0;
                std::set<char> common_elements = FindCommonElements();
                char element = *common_elements.begin();
                int score = part01::ScoreLetter(*common_elements.begin());
                return score;
            }
            return 0;
        }

        std::set<char> FindCommonElements()
        {
            return part01::FindCommonElements(
                part01::FindCommonElements(sacks_[0], sacks_[1]),
                sacks_[2]);
        }

    private:
        int i_;
        std::set<char> sacks_[3];
    };
} // namespace part02

#endif // DAY03_PART02_H_