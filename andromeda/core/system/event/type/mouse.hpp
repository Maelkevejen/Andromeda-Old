#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/structure/tuple.hpp"

namespace Andromeda::System::Event {
    namespace Mouse {
        struct Move : Event < Type::Move, Group::Input + Group::Mouse > {
            Move(System::Structure::Duo<int> position) : Event({Andromeda::System::Structure::Status::Event::Unused}), position({position}) {}
            Move(System::Structure::Duo<int> position, Andromeda::System::Structure::Status::Event status) : Event({status}), position({position}) {}
            System::Structure::Duo<int> position;
        };
        struct Scroll : Event < Type::Scroll, Group::Input + Group::Mouse > {
            Scroll(System::Structure::Duo<float> offset) : Event({Andromeda::System::Structure::Status::Event::Unused}), offset({offset}) {}
            Scroll(System::Structure::Duo<float> offset, Andromeda::System::Structure::Status::Event status) : Event({status}), offset({offset}) {}
            System::Structure::Duo<float> offset;
        };
    } /* Mouse */
} /* Andromeda::System::Event */