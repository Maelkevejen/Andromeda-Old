#pragma once

#include "andromeda/core/core.hpp"
#include "andromeda/core/system/structure/bitmask.hpp"
#include "andromeda/core/system/event/type/window.hpp"

namespace Andromeda::System::Graphics::Display {
    class Window {
      public:
        struct Position {
            int x, y;
        };
        struct Viewport {
            int width, height;
        };
        enum class Options {
            Default    = 0,
            Decorated  = Andromeda::Numerics::Bit(0),
            Resizable  = Andromeda::Numerics::Bit(1),
            Visible    = Andromeda::Numerics::Bit(2),
            Floating   = Andromeda::Numerics::Bit(3),
            Subscreen  = Andromeda::Numerics::Bit(4),
            Fullscreen = Andromeda::Numerics::Bit(5),
        };
        struct Configuration {
            std::string title;
            Position position;
            Viewport viewport;
            Options options;
        };
      public:
        virtual ~Window() = default;

        virtual void update() = 0;
    };
    Andromeda::Structure::Concept::Tag bitmask(Andromeda::System::Graphics::Display::Window::Options);
} /* Andromeda::System::Graphics::Display::Window */