#include "andromeda/core/system/structure/status.hpp"

#include "gtest/gtest.h"

TEST(Status, Runtime) {
    using namespace Andromeda::System::Structure::Status;
    EXPECT_NO_THROW({

        EXPECT_FALSE(Runtime::Activated == Runtime::Initialized || Runtime::Initialized == Runtime::Interrupted || Runtime::Interrupted == Runtime::Nullified || Runtime::Nullified == Runtime::Terminated);
    });
}

TEST(Status, Error) {
    using namespace Andromeda::System::Structure::Status;
    EXPECT_NO_THROW({
        EXPECT_FALSE(Error::Undefined == Error::None);
    });
}