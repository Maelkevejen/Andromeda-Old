#include "andromeda/core/system/structure/status.hpp"

#include "gtest/gtest.h"

TEST(Status, Runtime) {
    EXPECT_NO_THROW({
        auto activated = Andromeda::System::Structure::Status::Runtime::Activated;
        auto initialized = Andromeda::System::Structure::Status::Runtime::Initialized;
        auto interrupted = Andromeda::System::Structure::Status::Runtime::Interrupted;
        auto nullified = Andromeda::System::Structure::Status::Runtime::Nullified;
        auto terminated = Andromeda::System::Structure::Status::Runtime::Terminated;

        EXPECT_FALSE(activated == initialized || initialized == interrupted || interrupted == nullified || nullified == terminated);
    });
}

TEST(Status, Event) {
    EXPECT_NO_THROW({
        auto unused = Andromeda::System::Structure::Status::Event::Unused;
        EXPECT_TRUE(unused == unused);
    });
}

TEST(Status, Error) {
    EXPECT_NO_THROW({
        auto undefined = Andromeda::System::Structure::Status::Error::Undefined;
        EXPECT_TRUE(undefined == undefined);
    });
}