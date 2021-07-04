#include "andromeda/core/system/structure/tuple.hpp"

#include "gtest/gtest.h"

TEST(Duo, Integer) {
    auto duo = Andromeda::System::Structure::Duo<int> {2, 3};
    EXPECT_EQ(duo.α, 2);
    EXPECT_EQ(duo.β, 3);
}

TEST(Trio, Float) {
    auto trio = Andromeda::System::Structure::Trio<double> {2.2, 3.3, 4.4};
    EXPECT_FLOAT_EQ(trio.α, 2.2);
    EXPECT_FLOAT_EQ(trio.β, 3.3);
    EXPECT_FLOAT_EQ(trio.γ, 4.4);
}