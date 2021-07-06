#pragma once

#include "andromeda/core/core.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include <filesystem>

namespace Andromeda::System {
    class Log {
      public:
        struct Configuration {
            const std::string name;
            const std::filesystem::path log_directory;
            const std::size_t max_log_files;
            const std::size_t max_log_file_size;
            const std::size_t threads;
            const std::size_t workers;
        };
      public:
        Log() = delete;
        static void initialize(Log::Configuration configuration);
        static void shutdown() {
            spdlog::shutdown();
        }
        static std::shared_ptr<spdlog::logger> & core() {
            return s_Core;
        }
        static std::shared_ptr<spdlog::logger> & instance() {
            return s_Instance;
        }
      private:
        inline static std::shared_ptr<spdlog::logger> s_Core = nullptr;
        inline static std::shared_ptr<spdlog::logger> s_Instance = nullptr;
    };
} /* Andromeda::System */

#define LOG_LEVEL_NONE     0
#define LOG_LEVEL_CRITICAL 1
#define LOG_LEVEL_ERROR    2
#define LOG_LEVEL_WARN     3
#define LOG_LEVEL_INFO     4
#define LOG_LEVEL_DEBUG    5
#define LOG_LEVEL_TRACE    6

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_NONE
#endif

#if LOG_LEVEL == LOG_LEVEL_DEBUG
#undef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_TRACE
#endif

#define ANDROMEDA_CORE_CRITICAL(...)
#define ANDROMEDA_CRITICAL(...)
#define ANDROMEDA_CORE_ERROR(...)
#define ANDROMEDA_ERROR(...)
#define ANDROMEDA_CORE_ASSERT(x, ...)
#define ANDROMEDA_CORE_ASSERT_MESSAGE(x, y, ...)
#define ANDROMEDA_ASSERT(x, ...)
#define ANDROMEDA_ASSERT_MESSAGE(x, y, ...)
#define ANDROMEDA_CORE_WARN(...)
#define ANDROMEDA_WARN(...)
#define ANDROMEDA_CORE_INFO(...)
#define ANDROMEDA_INFO(...)
#define ANDROMEDA_CORE_TRACE(...)
#define ANDROMEDA_TRACE(...)

#if LOG_LEVEL >= LOG_LEVEL_CRITICAL
#undef ANDROMEDA_CORE_CRITICAL
#undef ANDROMEDA_CRITICAL
#define ANDROMEDA_CORE_CRITICAL(...)    ::Andromeda::System::Log::core()->critical(__VA_ARGS__)
#define ANDROMEDA_CRITICAL(...)         ::Andromeda::System::Log::instance()->critical(__VA_ARGS__)

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#undef ANDROMEDA_CORE_ERROR
#undef ANDROMEDA_ERROR
#define ANDROMEDA_CORE_ERROR(...)    ::Andromeda::System::Log::core()->error(__VA_ARGS__)
#define ANDROMEDA_ERROR(...)         ::Andromeda::System::Log::instance()->error(__VA_ARGS__)
#endif

#ifdef LOG_ASSERTIONS
#undef ANDROMEDA_CORE_ASSERT
#undef ANDROMEDA_CORE_ASSERT_MESSAGE
#undef ANDROMEDA_ASSERT
#undef ANDROMEDA_ASSERT_MESSAGE
#define ANDROMEDA_CORE_ASSERT(x, ...) {if(!(x)) { ANDROMEDA_CORE_ERROR("Assertion Failure: {0}", __VA_ARGS__); }}
#define ANDROMEDA_CORE_ASSERT_MESSAGE(x, y, ...) { if(!(x)) { ANDROMEDA_CORE_ERROR("Assertion Failure: " y, __VA_ARGS__); }}
#define ANDROMEDA_ASSERT(x, ...) { if(!(x)) { ANDROMEDA_ERROR("Assertion Failure: {0}", __VA_ARGS__); }}
#define ANDROMEDA_ASSERT_MESSAGE(x, y, ...) { if(!(x)) { ANDROMEDA_ERROR("Assertion Failure: " y, __VA_ARGS__); }}
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#undef ANDROMEDA_CORE_WARN
#undef ANDROMEDA_WARN
#define ANDROMEDA_CORE_WARN(...)    ::Andromeda::System::Log::core()->warn(__VA_ARGS__)
#define ANDROMEDA_WARN(...)         ::Andromeda::System::Log::instance()->warn(__VA_ARGS__)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#undef ANDROMEDA_CORE_INFO
#undef ANDROMEDA_INFO
#define ANDROMEDA_CORE_INFO(...)    ::Andromeda::System::Log::core()->info(__VA_ARGS__)
#define ANDROMEDA_INFO(...)         ::Andromeda::System::Log::instance()->info(__VA_ARGS__)
#endif

#if LOG_LEVEL >= LOG_LEVEL_TRACE
#undef ANDROMEDA_CORE_TRACE
#undef ANDROMEDA_TRACE
#define ANDROMEDA_CORE_TRACE(...)    ::Andromeda::System::Log::core()->trace(__VA_ARGS__)
#define ANDROMEDA_TRACE(...)         ::Andromeda::System::Log::instance()->trace(__VA_ARGS__)
#endif
#endif