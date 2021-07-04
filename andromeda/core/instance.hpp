#pragma once

#include <memory>
#include <string>

#include "andromeda/core/system/log/log.hpp"
#include "andromeda/core/system/structure/status.hpp"

namespace Andromeda {
    class Instance {
      public:
        struct Meta {
            std::string name;
            std::string engine;
        };
        struct State {
            System::Structure::Status::Runtime status;
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

    };
    std::unique_ptr<Instance> instantiate();
} /* Andromeda */