#pragma once

#include "andromeda/core/system/graphics/display/window.hpp"
#include "andromeda/core/system/event/type/keyboard.hpp"
#include "andromeda/core/system/event/type/mouse.hpp"

namespace Andromeda::System::Input {
    class State {
      public:
        static bool pressed(Andromeda::System::Input::Code::Keyboard::Key key, Andromeda::System::Graphics::Display::Window & window);
        static bool pressed(Andromeda::System::Input::Code::Keyboard::Mod mod, Andromeda::System::Graphics::Display::Window & window);
        static bool pressed(Andromeda::System::Input::Code::Mouse::Button button, Andromeda::System::Graphics::Display::Window & window);
        static Andromeda::System::Structure::Duo<double> mouse(Andromeda::System::Graphics::Display::Window & window);
    };
} /* Andromeda::System::Input */