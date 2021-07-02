#include "gtest/gtest.h"

#include "andromeda/core/system/log/log.hpp"

TEST(System, Log) {
    EXPECT_NO_THROW({
        Andromeda::System::Log::initialize({
            .name = "test",
            .log_directory = "logging/test.log",
            .max_log_files = 3,
            .max_log_file_size = 5 * 1024 * 1024,
            .threads = 8096,
            .workers = 1,
        });
        ANDROMEDA_CORE_INFO("[ Initialized / Andromeda / System / Log ]");
    });
}