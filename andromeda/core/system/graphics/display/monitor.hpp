#pragma once

#include "andromeda/core/system/event/type/monitor.hpp"
#include "andromeda/core/system/event/manager.hpp"

#include <string>

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
        struct Callbacks {
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Monitor::Connect> connect;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Monitor::Disconnect> disconnect;
        };
        struct Configuration {
            std::string title;
            Position position;
            Area area;
            Mode mode;
            Callbacks * callbacks;
        };
      public:
        virtual ~Monitor() = default;

        virtual void update() = 0;
    };
} /* Andromeda::System::Graphics::Display */