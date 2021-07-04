#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/structure/tuple.hpp"

namespace Andromeda::System::Event {
    namespace Window {
        struct Move : Event < Type::Move, Group::Instance + Group::Window > {
            System::Structure::Duo<int> position;
        };
        struct Resize : Event < Type::Resize, Group::Instance + Group::Window > {
            System::Structure::Duo<int> resize;
        };
        struct Close : Event < Type::Close, Group::Instance + Group::Window > {};
        struct Refresh : Event < Type::Refresh, Group::Instance + Group::Window > {};
        struct Focus : Event < Type::Focus, Group::Instance + Group::Window > {};
        struct Defocus : Event < Type::Defocus, Group::Instance + Group::Window > {};
        struct Maximize : Event < Type::Maximize, Group::Instance + Group::Window > {};
        struct Minimize : Event < Type::Minimize, Group::Instance + Group::Window > {};
        struct Restore : Event < Type::Restore, Group::Instance + Group::Window > {};
    } /* Window */
} /* Andromeda::System::Event */