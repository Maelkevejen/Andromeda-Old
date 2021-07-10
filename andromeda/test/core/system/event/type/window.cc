#include "andromeda/core/system/event/type/window.hpp"

#include "gtest/gtest.h"

TEST(Event, Move) {
    EXPECT_NO_THROW({
        auto move = Andromeda::System::Event::Window::Move({3, 2});
        EXPECT_EQ(move.status, Andromeda::System::Structure::Status::Event::Unused);
        move.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Resize) {
    EXPECT_NO_THROW({
        auto resize = Andromeda::System::Event::Window::Resize({3, 2});
        EXPECT_EQ(resize.status, Andromeda::System::Structure::Status::Event::Unused);
        resize.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Close) {
    EXPECT_NO_THROW({
        auto close = Andromeda::System::Event::Window::Close{};
        EXPECT_EQ(close.status, Andromeda::System::Structure::Status::Event::Unused);
        close.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Refresh) {
    EXPECT_NO_THROW({
        auto refresh = Andromeda::System::Event::Window::Refresh{};
        EXPECT_EQ(refresh.status, Andromeda::System::Structure::Status::Event::Unused);
        refresh.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Focus) {
    EXPECT_NO_THROW({
        auto focus = Andromeda::System::Event::Window::Focus{};
        EXPECT_EQ(focus.status, Andromeda::System::Structure::Status::Event::Unused);
        focus.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Defocus) {
    EXPECT_NO_THROW({
        auto defocus = Andromeda::System::Event::Window::Defocus{};
        EXPECT_EQ(defocus.status, Andromeda::System::Structure::Status::Event::Unused);
        defocus.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Maximize) {
    EXPECT_NO_THROW({
        auto maximize = Andromeda::System::Event::Window::Maximize{};
        EXPECT_EQ(maximize.status, Andromeda::System::Structure::Status::Event::Unused);
        maximize.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Minimize) {
    EXPECT_NO_THROW({
        auto minimize = Andromeda::System::Event::Window::Minimize{};
        EXPECT_EQ(minimize.status, Andromeda::System::Structure::Status::Event::Unused);
        minimize.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Restore) {
    EXPECT_NO_THROW({
        auto restore = Andromeda::System::Event::Window::Restore{};
        EXPECT_EQ(restore.status, Andromeda::System::Structure::Status::Event::Unused);
        restore.status = Andromeda::System::Structure::Status::Event::Used;
    });
}
