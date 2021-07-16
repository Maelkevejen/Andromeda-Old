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

TEST(Event, Press) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto press = Andromeda::System::Event::Mouse::Button::Press(Andromeda::System::Input::Code::Mouse::Button::Right);
    });
}

TEST(Event, Release) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto release = Andromeda::System::Event::Mouse::Button::Release(Andromeda::System::Input::Code::Mouse::Button::Right);
    });
}