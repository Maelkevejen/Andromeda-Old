#include "andromeda/core/system/event/type/window.hpp"

#include "andromeda/core/system/event/manager.hpp"

#include "gtest/gtest.h"

TEST(Event, Move) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]] auto move = Andromeda::System::Event::Window::Move({3, 2});
    });
}

TEST(Event, Resize) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]] auto resize = Andromeda::System::Event::Window::Resize({3, 2});
    });
}

TEST(Event, Close) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  Andromeda::System::Event::Window::Close close;
    });
}

TEST(Event, Refresh) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  Andromeda::System::Event::Window::Refresh refresh;
    });
}

TEST(Event, Focus) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  Andromeda::System::Event::Window::Focus focus;
    });
}

TEST(Event, Defocus) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  Andromeda::System::Event::Window::Defocus defocus;
    });
}

TEST(Event, Maximize) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  Andromeda::System::Event::Window::Maximize maximize;
    });
}

TEST(Event, Minimize) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]]  Andromeda::System::Event::Window::Minimize minimize;
    });
}

TEST(Event, Restore) {
    EXPECT_NO_THROW({
        [[ maybe_unused ]] Andromeda::System::Event::Window::Restore restore;
    });
}


TEST(Event, Serial_Callback) {
    auto callback = [](Andromeda::System::Event::Window::Move move) {
        EXPECT_TRUE(move.position == Andromeda::System::Structure::Duo<int>({0,0}));
    };
    Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Move> manager;
    manager.listen(callback);
    Andromeda::System::Event::Window::Move event1({0,0});
    manager.transmit(event1);
    Andromeda::System::Event::Window::Move event2({0,0});
    manager.deafen(callback);
    manager.transmit(event1);
    manager.listen(callback);
    manager.transmit(event2);
}

TEST(Event, Parallel_Callback) {
    auto callback = [](Andromeda::System::Event::Window::Close) {

    };
    auto callback2 = [](Andromeda::System::Event::Window::Close) {

    };
    auto callback3 = [](Andromeda::System::Event::Window::Close) {

    };
    Andromeda::System::Event::Manager::Parallel<Andromeda::System::Event::Window::Close> manager;
    manager.listen(callback);
    manager.listen(callback2);
    Andromeda::System::Event::Window::Close event1;
    Andromeda::System::Event::Window::Close event2;
    manager.queue(event1);
    manager.queue(event2);
    manager.transmit();
    manager.deafen(callback);
    manager.transmit();
    manager.listen(callback2);
    manager.transmit();
    manager.clear();
    Andromeda::System::Event::Window::Close event3;
    manager.queue(event3);
    manager.deafen(callback);
    manager.deafen(callback2);
    manager.listen(callback3);
    manager.transmit();
}