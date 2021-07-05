#pragma once

#include <string>
#include <memory>

namespace Andromeda::System::Graphics::Display {
    class Monitor {
      public:
        struct Position {
            int x, y;
        };
        struct Area {
            int x, y;
            int width, height;
        };
        struct Mode {
            int red, green, blue;
            int frequency;
            int width, height;
        };
        struct Configuration {
            std::string title;
            Position position;
            Area area;
            Mode mode;
        };
      public:
        virtual ~Monitor() = default;

        virtual void configure(Monitor::Configuration configuration) = 0;
        virtual void update() = 0;

        static std::unique_ptr<Monitor> create(const Monitor::Configuration configuration);
    };
} /* Andromeda::System::Graphics::Display */