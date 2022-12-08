#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "parse_input.h"

#include <algorithm>
#include <utility>
#include <vector>

using ::testing::ElementsAre;
using ::testing::FieldsAre;
using ::testing::Pair;

namespace parse_input
{
    namespace
    {
        MATCHER_P(MoveEq, move, "")
        {
            return arg.quantity == move.quantity &&
                   arg.from == move.from &&
                   arg.to == move.to;
        }

        TEST(Util, ParseStackLine)
        {
            InputParser parser;
            parser.ParseStackLine("                    [Q]     [P] [P]");
            EXPECT_THAT(
                parser.GetStack(),
                ElementsAre(Pair(6, ElementsAre('Q')),
                            Pair(8, ElementsAre('P')),
                            Pair(9, ElementsAre('P'))));
        }

        TEST(ParseInput, ParseMove)
        {
            InputParser parser;
            parser.ParseMove("move 1 from 2 to 1");
            parser.ParseMove("move 3 from 1 to 2");
            EXPECT_THAT(parser.GetMoves(),
                        ElementsAre(
                            MoveEq(move::Move({1, 2, 1})),
                            MoveEq(move::Move({3, 1, 2}))));
        }

        TEST(ParseInput, ParseInput)
        {
            InputParser parser;
            parser.ParseLine("    [D]    ");
            parser.ParseLine("[N] [C]    ");
            parser.ParseLine("[Z] [M] [P]");
            parser.ParseLine(" 1   2   3 ");
            parser.ParseLine(""); // Reverses the order of each stack.
            parser.ParseLine("move 1 from 2 to 1");
            parser.ParseLine("move 3 from 1 to 3");
            parser.ParseLine("move 2 from 2 to 1");
            parser.ParseLine("move 1 from 1 to 2");
            EXPECT_THAT(parser.GetStack(),
                        ElementsAre(
                            Pair(1, ElementsAre('Z', 'N')),
                            Pair(2, ElementsAre('M', 'C', 'D')),
                            Pair(3, ElementsAre('P'))));
            EXPECT_THAT(parser.GetMoves(),
                        ElementsAre(
                            MoveEq(move::Move({1, 2, 1})),
                            MoveEq(move::Move({3, 1, 3})),
                            MoveEq(move::Move({2, 2, 1})),
                            MoveEq(move::Move({1, 1, 2}))));
        }
    }
}