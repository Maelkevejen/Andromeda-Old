#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/structure/tuple.hpp"

namespace Andromeda::System::Event {
    namespace Mouse {
        struct Move : Event < Type::Move, Group::Input + Group::Mouse > {
            System::Structure::Duo<int> position;
        };
        struct Scroll : Event < Type::Scroll, Group::Input + Group::Mouse > {
            System::Structure::Duo<float> offset;
        };
    } /* Mouse */
} /* Andromeda::System::Event */