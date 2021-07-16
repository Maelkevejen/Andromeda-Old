#include "andromeda/core/system/event/event.hpp"

#include "gtest/gtest.h"

struct Basic : Andromeda::System::Event::Event<Andromeda::System::Event::Type::Group, Andromeda::System::Event::Group::Undefined> {};

TEST(Event, Create) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]] auto test = Basic();
    });
}