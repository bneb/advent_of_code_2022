#include <gtest/gtest.h>
#include "part02.h"

namespace part02
{
    namespace
    {
        TEST(part02Test, Coordinate)
        {
            part02::ElfGroupCoordinator egc;
            EXPECT_EQ(egc.Coordinate("New"), 0);
            EXPECT_EQ(egc.Coordinate("Gen"), 0);
            EXPECT_EQ(egc.Coordinate("eEL"), 5);
            EXPECT_EQ(egc.Coordinate("Old"), 0);
            EXPECT_EQ(egc.Coordinate("oWl"), 0);
            EXPECT_EQ(egc.Coordinate("lEG"), 12);
        }

    } // namespace
} // namespace part02