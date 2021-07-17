#pragma once

#include "andromeda/core/core.hpp"
#include "andromeda/core/system/input/manager.hpp"
#include "andromeda/core/system/event/type/window.hpp"
#include "andromeda/core/system/event/manager.hpp"
#include "andromeda/core/system/structure/bitmask.hpp"

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
        struct Callbacks {
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Move, const Window *> move;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Resize, const Window *> resize;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Close, const Window *> close;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Refresh, const Window *> refresh;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Focus, const Window *> focus;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Defocus, const Window *> defocus;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Maximize, const Window *> maximize;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Minimize, const Window *> minimize;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Restore, const Window *> restore;
            Andromeda::System::Input::Manager::Callbacks<const Window *> input;
        };
        struct Configuration {
            std::string title;
            Position position;
            Viewport viewport;
            Options options;
            Callbacks * callbacks;
            Window * window;
        };
      public:
        virtual ~Window() = default;

        virtual void update() = 0;

      public:
        virtual bool pressed(Andromeda::System::Input::Code::Keyboard::Key key) const = 0;
        virtual bool pressed(Andromeda::System::Input::Code::Keyboard::Mod mod) const = 0;
        virtual bool pressed(Andromeda::System::Input::Code::Mouse::Button button) const = 0;
        virtual Andromeda::System::Structure::Duo<double> mouse() const = 0;

    };
    Andromeda::Structure::Concept::Tag bitmask(Andromeda::System::Graphics::Display::Window::Options);
} /* Andromeda::System::Graphics::Display::Window */