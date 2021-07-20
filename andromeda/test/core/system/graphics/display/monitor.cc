#include "andromeda/core/system/graphics/display/monitor.hpp"

#include "gtest/gtest.h"

TEST(Monitor, Types) {
    EXPECT_NO_THROW({
        auto position = Andromeda::System::Graphics::Display::Monitor::Position({0, 0});
        auto area = Andromeda::System::Graphics::Display::Monitor::Area({0, 0, 800, 600});
        auto mode =  Andromeda::System::Graphics::Display::Monitor::Mode({128, 128, 128, 144, 800, 600});
        auto configuration = Andromeda::System::Graphics::Display::Monitor::Configuration({"TEST", position, area, mode});
        EXPECT_TRUE(configuration.title == "TEST");
    });
}