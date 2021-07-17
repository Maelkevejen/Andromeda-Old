#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/structure/tuple.hpp"

namespace Andromeda::System::Event {
    namespace Window {
        struct Move : public Event < Type::Move, Group::Instance + Group::Window > {
            Move(System::Structure::Duo<int> position) : position({position}) {}
            System::Structure::Duo<int> position;
        };
        struct Resize : public Event < Type::Resize, Group::Instance + Group::Window > {
            Resize(System::Structure::Duo<int> resize) : resize({resize}) {}
            System::Structure::Duo<int> resize;
        };
        struct Close : public Event < Type::Close, Group::Instance + Group::Window > {
            Close() {}
        };
        struct Refresh : public Event < Type::Refresh, Group::Instance + Group::Window > {
            Refresh() {}
        };
        struct Focus : public Event < Type::Focus, Group::Instance + Group::Window > {
            Focus() {}
        };
        struct Defocus : public Event < Type::Defocus, Group::Instance + Group::Window > {
            Defocus() {}
        };
        struct Maximize : public Event < Type::Maximize, Group::Instance + Group::Window > {
            Maximize() {}
        };
        struct Minimize : public Event < Type::Minimize, Group::Instance + Group::Window > {
            Minimize() {}
        };
        struct Restore : public Event < Type::Restore, Group::Instance + Group::Window > {
            Restore() {}
        };
    } /* Window */
} /* Andromeda::System::Event */