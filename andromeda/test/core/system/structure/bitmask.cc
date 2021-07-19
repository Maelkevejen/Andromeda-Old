#include "andromeda/core/system/structure/bitmask.hpp"

#include "andromeda/core/core.hpp"

#include "gtest/gtest.h"

enum class Test_Enum {
    None = 0,
    Test1 = Andromeda::Numerics::Bit(0),
    Test2 = Andromeda::Numerics::Bit(1),
    Test4 = Andromeda::Numerics::Bit(2),
    Test8 = Andromeda::Numerics::Bit(3),
    Test16 = Andromeda::Numerics::Bit(4),
    Test32 = Andromeda::Numerics::Bit(5),
    Test64 = Andromeda::Numerics::Bit(6),
};
Andromeda::Structure::Concept::Tag bitmask(Test_Enum);

TEST(Bitmask, Common) {
    auto test = Test_Enum::Test2 + Test_Enum::Test4 + Test_Enum::Test32;
    auto test2 = Test_Enum::Test16 + Test_Enum::Test8 + Test_Enum::Test32;
    EXPECT_TRUE(static_cast<int>(test2) == 16+8+32);
    EXPECT_FALSE((Test_Enum::Test2+Test_Enum::Test16) == Test_Enum::Test16);
    EXPECT_FALSE((test >> test2));
    EXPECT_FALSE(Test_Enum::Test1 == Test_Enum::Test2 || Test_Enum::Test2 + Test_Enum::Test32 + Test_Enum::Test16 == Test_Enum::Test16);
}

TEST(Bitmask, Add) {
    auto test = Test_Enum::Test2 + Test_Enum::Test4;
    EXPECT_TRUE((test >> Test_Enum::Test2));
    EXPECT_TRUE((test >> Test_Enum::Test4));
    EXPECT_TRUE(test == Test_Enum::Test2 + Test_Enum::Test4);
}

TEST(Bitmask, Remove) {
    auto test = Test_Enum::Test2 + Test_Enum::Test4;
    test -= Test_Enum::Test4;
    EXPECT_TRUE(test == Test_Enum::Test2);
    EXPECT_FALSE((test >> Test_Enum::Test4));
}

TEST(Bitmask, And) {
    EXPECT_TRUE((Test_Enum::Test2 + Test_Enum::Test16) >> Test_Enum::Test16);
    EXPECT_FALSE((Test_Enum::Test2 + Test_Enum::Test16) >> Test_Enum::Test4);
}

TEST(Bitmask, Sets) {
    auto test = Test_Enum::Test16 + Test_Enum::Test8;
    auto test2 = Test_Enum::Test16 + Test_Enum::Test4;
    auto test3 = Test_Enum::Test2 + Test_Enum::Test8 + Test_Enum::Test16 + Test_Enum::Test32;
    EXPECT_TRUE(test3 >> test);
    EXPECT_FALSE((test2 >> test3));
    EXPECT_TRUE((test2 >> Test_Enum::None));
}