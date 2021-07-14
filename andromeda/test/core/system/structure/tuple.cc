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

TEST(Quartet, Integer) {
    auto quartet = Andromeda::System::Structure::Quartet<int> {2, 3, 5, 7};
    EXPECT_EQ(quartet.α, 2);
    EXPECT_EQ(quartet.β, 3);
    EXPECT_EQ(quartet.γ, 5);
    EXPECT_EQ(quartet.δ, 7);
}

TEST(Quintet, Integer) {
    auto quintet = Andromeda::System::Structure::Quintet<int> {2, 3, 5, 7, 11};
    EXPECT_EQ(quintet.α, 2);
    EXPECT_EQ(quintet.β, 3);
    EXPECT_EQ(quintet.γ, 5);
    EXPECT_EQ(quintet.δ, 7);
    EXPECT_EQ(quintet.ε, 11);
}