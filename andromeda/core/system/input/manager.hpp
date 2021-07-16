#pragma once

#include "andromeda/core/system/event/type/keyboard.hpp"
#include "andromeda/core/system/event/type/mouse.hpp"
#include "andromeda/core/system/event/manager.hpp"

namespace Andromeda::System::Input {
    namespace Callbacks {
        struct Keyboard {
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Keyboard::Key::Press> press;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Keyboard::Key::Release> release;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Keyboard::Key::Type> type;
        };
        struct Mouse {
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Move> move;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Scroll> scroll;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Button::Press> press;
            Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Mouse::Button::Release> release;
        };
    } /* Callbacks */
    namespace Manager {
        struct Callbacks {
            Andromeda::System::Input::Callbacks::Keyboard keyboard;
            Andromeda::System::Input::Callbacks::Mouse mouse;
        };
    }; /* Manager */
} /* Andromeda::System::Input */