#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "part01.h"

#include <utility>

namespace part01
{
    namespace
    {
        TEST(Util, DetectFullOverlap)
        {
            EXPECT_TRUE(DetectFullOverlap(2, 3, 1, 4));
            EXPECT_FALSE(DetectFullOverlap(2, 3, 1, 2));
        }
    }
}