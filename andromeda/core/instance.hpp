#pragma once

#include <memory>
#include <string>

#include "andromeda/core/system/logging/log.hpp"

namespace Andromeda {
    class Instance {
      public:
        struct Meta {
            std::string name;
            std::string engine;
        };
        struct State {
            int status;
            bool active;
        };
        struct Configuration {
            Instance::Meta meta;
            Logging::Log::Configuration log;
        };
      public:
        virtual ~Instance() = default;

        virtual void initialize() = 0;

        virtual const Instance::Configuration & configuration() const = 0;
        virtual const Instance::State & state() const = 0;

    };
    std::unique_ptr<Instance> instantiate();
} /* Andromeda */