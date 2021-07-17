#pragma once

#include "andromeda/core/core.hpp"
#include "andromeda/core/system/structure/bitmask.hpp"

#include <string>
#include <memory>

namespace Andromeda::System::Graphics {
    class Engine {
      public:
        enum class Type {
            None = 0,
            Vulkan,
        };
        struct Info {
            const std::string application;
            const std::string engine;
        };
        enum class Options {
            Default = 0,
        };
        struct Configuration {
            Engine::Type type;
            Info info;
            Options options;
        };
      public:
        virtual ~Engine() = default;

        virtual void initialize() = 0;

        static std::unique_ptr<Engine> instantiate(Engine::Configuration configuration);
    };
    Andromeda::Structure::Concept::Tag bitmask(Andromeda::System::Graphics::Engine::Options);
} /* Andromeda::System::Graphics */