#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/input/code/key.hpp"

namespace Andromeda::System::Event {
    namespace Keyboard::Key {
        struct Press : public Event < Andromeda::System::Event::Type::Press, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Keyboard > {
            Press(Andromeda::System::Input::Code::Key key, int repeats) : key(key), repeats(repeats) {}
            Press(Andromeda::System::Input::Code::Key key) : key(key), repeats(0) {}
            Andromeda::System::Input::Code::Key key;
            int repeats;
        };
        struct Release : public Event < Andromeda::System::Event::Type::Release, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Keyboard > {
            Release(Andromeda::System::Input::Code::Key key) : key(key) {}
            Andromeda::System::Input::Code::Key key;
        };
        struct Type : public Event < Andromeda::System::Event::Type::Type, Andromeda::System::Event::Group::Input + Group::Keyboard > {
            Type(Andromeda::System::Input::Code::Key key) : key(key) {}
            Andromeda::System::Input::Code::Key key;
        };
    } /* Keyboard::Key */
} /* Andromeda::System::Event */