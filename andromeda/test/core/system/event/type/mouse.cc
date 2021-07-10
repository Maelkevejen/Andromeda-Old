#include "andromeda/core/system/event/type/mouse.hpp"

#include "gtest/gtest.h"

TEST(Event, Move) {
    EXPECT_NO_THROW({
        auto move = Andromeda::System::Event::Mouse::Move({3, 2});
        EXPECT_EQ(move.status, Andromeda::System::Structure::Status::Event::Unused);
        move.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Scroll) {
    EXPECT_NO_THROW({
        auto scroll = Andromeda::System::Event::Mouse::Scroll({20.0, -1.0});
        EXPECT_EQ(scroll.status, Andromeda::System::Structure::Status::Event::Unused);
        scroll.status = Andromeda::System::Structure::Status::Event::Used;
    });
}