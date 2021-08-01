#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/input/code/key.hpp"

namespace Andromeda::System::Event {
    template <> struct Event < Andromeda::System::Event::Type::Press, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Keyboard > {
        Event(Andromeda::System::Input::Code::Keyboard::Key key, Andromeda::System::Input::Code::Keyboard::Mod mod, int repeats) : key(key), mod(mod), repeats(repeats) {}
        Event(Andromeda::System::Input::Code::Keyboard::Key key, int repeats) : key(key), repeats(repeats) {}
        Event(Andromeda::System::Input::Code::Keyboard::Key key) : key(key), repeats(0) {}
        Andromeda::System::Input::Code::Keyboard::Key key;
        Andromeda::System::Input::Code::Keyboard::Mod mod;
        int repeats;
    };
    namespace Keyboard::Key {
        using Press = Andromeda::System::Event::Event < Andromeda::System::Event::Type::Press, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Keyboard >;
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