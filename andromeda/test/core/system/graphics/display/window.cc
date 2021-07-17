#include "andromeda/core/system/graphics/display/window.hpp"

#include "gtest/gtest.h"

TEST(Window, Types) {
    EXPECT_NO_THROW({
        auto position = Andromeda::System::Graphics::Display::Window::Position({0, 0});
        auto viewport = Andromeda::System::Graphics::Display::Window::Viewport({800, 600});
        auto options =  Andromeda::System::Graphics::Display::Window::Options::Default;
        auto configuration = Andromeda::System::Graphics::Display::Window::Configuration({"TEST", position, viewport, options, {}, nullptr});
        EXPECT_TRUE(configuration.title == "TEST");
    });
}