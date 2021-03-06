#pragma once

#include "andromeda/core/system/log/log.hpp"
#include "andromeda/core/system/structure/status.hpp"

#include <memory>
#include <string>

namespace Andromeda {
    class Instance {
      public:
        struct Meta {
            std::string name;
            std::string engine;
        };
        struct State {
            System::Structure::Status::Runtime status;
            System::Structure::Status::Error error;
        };
        struct Configuration {
            Instance::Meta meta;
            System::Log::Configuration log;
        };
      public:
        virtual ~Instance() = default;

        virtual void initialize() = 0;
        virtual void execute() = 0;
        virtual void interrupt() = 0;
        virtual void terminate() = 0;

        virtual const Instance::Configuration & configuration() const = 0;
        virtual const Instance::State & state() const = 0;
        virtual int code() const = 0;

        static std::unique_ptr<Instance> instantiate();
    };
} /* Andromeda */