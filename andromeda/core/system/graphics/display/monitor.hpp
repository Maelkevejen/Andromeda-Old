#pragma once

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
        struct Configuration {
            std::string title;
            Position position;
            Area area;
            Mode mode;
        };
      public:
        virtual ~Monitor() = default;

        virtual void update() = 0;
    };
} /* Andromeda::System::Graphics::Display */