#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "part02.h"

#include <utility>

namespace part02
{
    namespace
    {
        TEST(Util, DetectPartialOverlap)
        {
            EXPECT_TRUE(DetectPartialOverlap(2, 3, 1, 2));
            EXPECT_TRUE(DetectPartialOverlap(2, 4, 3, 9));
            EXPECT_FALSE(DetectPartialOverlap(2, 4, 5, 9));
        }
    }
}