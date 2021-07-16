#include "andromeda/core/system/event/type/keyboard.hpp"

#include "gtest/gtest.h"


TEST(Event, Press) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto press = Andromeda::System::Event::Keyboard::Key::Press(Andromeda::System::Input::Code::Keyboard::Key::Tab);
    });
}

TEST(Event, Release) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto press = Andromeda::System::Event::Keyboard::Key::Release(Andromeda::System::Input::Code::Keyboard::Key::Tab);
    });
}

TEST(Event, Type) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto press = Andromeda::System::Event::Keyboard::Key::Type(Andromeda::System::Input::Code::Keyboard::Key::Tab);
    });
}