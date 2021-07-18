#pragma once

#include "andromeda/core/system/event/manager.hpp"
#include "andromeda/core/system/event/type/keyboard.hpp"
#include "andromeda/core/system/event/type/mouse.hpp"

namespace Andromeda::System::Input {
    namespace Callbacks {
        template<class ... Arguments>
        struct Keyboard {
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Keyboard::Key::Press, Arguments ...> press;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Keyboard::Key::Release, Arguments ...> release;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Keyboard::Key::Type, Arguments ...> type;
        };
        template<class ... Arguments>
        struct Mouse {
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Move, Arguments ...> move;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Drag, Arguments ...> drag;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Scroll, Arguments ...> scroll;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Button::Press, Arguments ...> press;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Button::Release, Arguments ...> release;
        };
    } /* Callbacks */
    namespace Manager {
        template <class ... Arguments>
        struct Callbacks {
            Andromeda::System::Input::Callbacks::Keyboard<Arguments ...> keyboard;
            Andromeda::System::Input::Callbacks::Mouse<Arguments ...> mouse;
        };
    }; /* Manager */
} /* Andromeda::System::Input */