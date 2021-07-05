#include "andromeda/core/core.hpp"

#include "gtest/gtest.h"

TEST(Core, Constants) {
    EXPECT_EQ(1, Andromeda::Numerics::Bit(0));
    EXPECT_EQ(2, Andromeda::Numerics::Bit(1));
    EXPECT_EQ(4, Andromeda::Numerics::Bit(2));
    EXPECT_EQ(8, Andromeda::Numerics::Bit(3));
    EXPECT_EQ(64, Andromeda::Numerics::Bit(6));
    EXPECT_EQ("Andromeda", Andromeda::Titles::engine);
}