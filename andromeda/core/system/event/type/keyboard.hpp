#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/input/code/key.hpp"

namespace Andromeda::System::Event {
    namespace Keyboard::Key {
        struct Press : public Event < Andromeda::System::Event::Type::Press, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Keyboard > {
            Press(Andromeda::System::Input::Code::Keyboard::Key key, Andromeda::System::Input::Code::Keyboard::Mod mod, int repeats) : key(key), mod(mod), repeats(repeats) {}
            Press(Andromeda::System::Input::Code::Keyboard::Key key, int repeats) : key(key), repeats(repeats) {}
            Press(Andromeda::System::Input::Code::Keyboard::Key key) : key(key), repeats(0) {}
            Andromeda::System::Input::Code::Keyboard::Key key;
            Andromeda::System::Input::Code::Keyboard::Mod mod;
            int repeats;
        };
        struct Release : public Event < Andromeda::System::Event::Type::Release, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Keyboard > {
            Release(Andromeda::System::Input::Code::Keyboard::Key key, Andromeda::System::Input::Code::Keyboard::Mod mod) : key(key), mod(mod) {}
            Release(Andromeda::System::Input::Code::Keyboard::Key key) : key(key) {}
            Andromeda::System::Input::Code::Keyboard::Key key;
            Andromeda::System::Input::Code::Keyboard::Mod mod;
        };
        struct Type : public Event < Andromeda::System::Event::Type::Type, Andromeda::System::Event::Group::Input + Group::Keyboard > {
            Type(Andromeda::System::Input::Code::Keyboard::Key key, Andromeda::System::Input::Code::Keyboard::Mod mod) : key(key), mod(mod) {}
            Type(Andromeda::System::Input::Code::Keyboard::Key key) : key(key) {}
            Andromeda::System::Input::Code::Keyboard::Key key;
            Andromeda::System::Input::Code::Keyboard::Mod mod;
        };
    } /* Keyboard::Key */
} /* Andromeda::System::Event */