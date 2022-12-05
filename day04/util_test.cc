#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "util.h"

#include <utility>

using ::testing::FieldsAre;

namespace util
{
    namespace
    {
        TEST(Util, ParseRange)
        {
            EXPECT_THAT(ParseRange("241-1131"), FieldsAre(241, 1131));
        }

        TEST(Util, ParseAssignmentString)
        {
            EXPECT_THAT(ParseAssignmentString("1-21,312-313"),
                        FieldsAre(Pair(1, 21), Pair(312, 313)));
        }
    }
}