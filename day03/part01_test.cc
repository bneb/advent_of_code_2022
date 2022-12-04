#include <gtest/gtest.h>
#include "part01.h"

namespace part01
{
    namespace
    {
        TEST(Part01Test, ScoreLetterWorksForUppercase)
        {
            EXPECT_EQ(ScoreLetter('A'), 27);
            EXPECT_EQ(ScoreLetter('B'), 28);
            EXPECT_EQ(ScoreLetter('Z'), 52);
        }

        TEST(Part01Test, ScoreLetterWorksForLowercase)
        {
            EXPECT_EQ(ScoreLetter('a'), 1);
            EXPECT_EQ(ScoreLetter('b'), 2);
            EXPECT_EQ(ScoreLetter('z'), 26);
        }

        TEST(Part01Test, GetRucksacks)
        {
            auto [l, r] = GetRucksacks("aBcD");
            EXPECT_EQ(l, std::set<char>({'B', 'a'}));
            EXPECT_EQ(r, std::set<char>({'D', 'c'}));
        }

        TEST(Part01Test, FindCommonElements)
        {
            EXPECT_EQ(
                FindCommonElements(
                    std::set<char>({'B', 'a', 'D'}),
                    std::set<char>({'a', 's', '$'})),
                std::set<char>({'a'}));
        }

        TEST(Part01Test, ScoreRucksack)
        {
            EXPECT_EQ(ScoreRucksack("Swellegg"), 5);
        }

    } // namespace
} // namespace part01