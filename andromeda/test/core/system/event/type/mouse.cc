#include "andromeda/core/system/event/type/mouse.hpp"

#include "gtest/gtest.h"

TEST(Event, Move) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto move = Andromeda::System::Event::Mouse::Move({3, 2});
    });
}

TEST(Event, Scroll) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto scroll = Andromeda::System::Event::Mouse::Scroll({20.0, -1.0});
    });
}