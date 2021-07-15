#include "andromeda/core/system/platform/linux/graphics/display/manager.hpp"

#include "gtest/gtest.h"

TEST(Manager, DISABLED_Window) {
    EXPECT_NO_THROW({
        auto dm = Andromeda::System::Graphics::Display::Manager::instantiate();
        dm->create(Andromeda::System::Graphics::Display::Window::Configuration{
            .title = "test",
            .position = {0, 0},
            .viewport = {10, 10},
            .options = Andromeda::System::Graphics::Display::Window::Options::Subscreen,
        });
    });
}