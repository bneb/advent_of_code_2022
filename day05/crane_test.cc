#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "crane.h"

#include <algorithm>
#include <utility>
#include <vector>

using ::testing::ElementsAre;
using ::testing::FieldsAre;
using ::testing::Pair;

namespace crane
{
    namespace
    {
        TEST(Crane, Move)
        {
            auto s = new std::map<int, std::vector<char>>(
                {{1, std::vector<char>({'A', 'B', 'C'})},
                 {3, std::vector<char>({'D', 'E'})}});
            auto m = std::vector<move::Move>({move::Move({1, 1, 3}),
                                              move::Move({2, 3, 2})});
            auto stacks = std::unique_ptr<std::map<int, std::vector<char>>>(s);
            auto moves = std::make_unique<std::vector<move::Move>>(m);
            Crane crane(std::move(stacks), std::move(moves));
            crane.MoveAll();
            EXPECT_THAT(crane.GetTopCrates(),
                        ElementsAre('B', 'C', 'D'));
            EXPECT_THAT(crane.GetStacks(),
                        ElementsAre(
                            Pair(1, ElementsAre('A', 'B')),
                            Pair(2, ElementsAre('E', 'C')),
                            Pair(3, ElementsAre('D'))));
        }
    }
}