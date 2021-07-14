#include "andromeda/core/system/event/manager.hpp"

#include "gtest/gtest.h"

TEST(Manager, Dispatch) {
    auto callback = [](Andromeda::System::Event::Window::Close & event) {
        EXPECT_TRUE(event.status == Andromeda::System::Structure::Status::Event::Unused);
    };
    EXPECT_NO_THROW({
        Andromeda::System::Event::Manager<Andromeda::System::Event::Window::Close> window_close_manager;
        window_close_manager.subscribe(callback);
        window_close_manager.series();
    });
}