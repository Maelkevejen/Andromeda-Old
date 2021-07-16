#include "andromeda/core/system/event/type/monitor.hpp"

#include "gtest/gtest.h"

TEST(Event, Connect) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto connect = Andromeda::System::Event::Monitor::Connect();
    });
}

TEST(Event, Disconnect) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  auto disconnect = Andromeda::System::Event::Monitor::Disconnect();
    });
}