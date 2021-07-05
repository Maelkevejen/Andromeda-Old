#pragma once

#include "andromeda/core/core.hpp"
#include "andromeda/core/system/event/type/window.hpp"

#include <memory>

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
            Fullscreen = Andromeda::Numerics::Bit(4),
        };
        Andromeda::Structure::Concept::Tag bitmask(Andromeda::System::Graphics::Display::Window::Options);
        struct Configuration {
            std::string title;
            Position position;
            Viewport viewport;
            Options options;
        };
      public:
        virtual ~Window() = default;

        virtual void configure(Window::Configuration configuration) = 0;
        virtual void update() = 0;

        static std::unique_ptr<Window> create(const Window::Configuration configuration);
    };
} /* Andromeda::System::Graphics::Display::Window */