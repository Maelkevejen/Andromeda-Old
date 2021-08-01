#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/input/code/key.hpp"
#include "andromeda/core/system/input/code/mouse.hpp"
#include "andromeda/core/system/structure/tuple.hpp"

namespace Andromeda::System::Event {
    template <> struct Event < Andromeda::System::Event::Type::Press, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Mouse > {
        Event(Andromeda::System::Input::Code::Mouse::Button button, Andromeda::System::Input::Code::Keyboard::Mod mod) : button(button), mod(mod) {}
        Event(Andromeda::System::Input::Code::Mouse::Button button) : button(button) {}
        Andromeda::System::Input::Code::Mouse::Button button;
        Andromeda::System::Input::Code::Keyboard::Mod mod;
    };
    namespace Mouse {
        struct Move : public Event < Type::Move, Group::Input + Group::Mouse > {
            Move(System::Structure::Duo<double> position) : position({position}) {}
            System::Structure::Duo<double> position;
        };
        struct Scroll : public Event < Type::Scroll, Group::Input + Group::Mouse > {
            Scroll(System::Structure::Duo<double> offset) : offset({offset}) {}
            System::Structure::Duo<double> offset;
        };

        namespace Button {
            using Press = Andromeda::System::Event::Event < Andromeda::System::Event::Type::Press, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Mouse >;
            struct Release : public Event < Andromeda::System::Event::Type::Release, Andromeda::System::Event::Group::Input + Andromeda::System::Event::Group::Keyboard > {
                Release(Andromeda::System::Input::Code::Mouse::Button button, Andromeda::System::Input::Code::Keyboard::Mod mod) : button(button), mod(mod) {}
                Release(Andromeda::System::Input::Code::Mouse::Button button) : button(button) {}
                Andromeda::System::Input::Code::Mouse::Button button;
                Andromeda::System::Input::Code::Keyboard::Mod mod;
            };
        }; /* Button */
    } /* Mouse */
} /* Andromeda::System::Event */