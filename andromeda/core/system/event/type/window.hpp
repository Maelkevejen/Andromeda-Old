#pragma once

#include "andromeda/core/system/event/event.hpp"

#include "andromeda/core/system/structure/tuple.hpp"

namespace Andromeda::System::Event {
    namespace Window {
        struct Move : public Event < Type::Move, Group::Instance + Group::Window > {
            Move(System::Structure::Duo<int> position) : Event({Andromeda::System::Structure::Status::Event::Unused}), position({position}) {}
            Move(System::Structure::Duo<int> position, Andromeda::System::Structure::Status::Event status) : Event({status}), position({position}) {}
            System::Structure::Duo<int> position;
        };
        struct Resize : public Event < Type::Resize, Group::Instance + Group::Window > {
            Resize(System::Structure::Duo<int> resize) : Event({Andromeda::System::Structure::Status::Event::Unused}), resize({resize}) {}
            Resize(System::Structure::Duo<int> resize, Andromeda::System::Structure::Status::Event status) : Event({status}), resize({resize}) {}
            System::Structure::Duo<int> resize;
        };
        struct Close : public Event < Type::Close, Group::Instance + Group::Window > {
            Close() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
        };
        struct Refresh : public Event < Type::Refresh, Group::Instance + Group::Window > {
            Refresh() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
        };
        struct Focus : public Event < Type::Focus, Group::Instance + Group::Window > {
            Focus() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
        };
        struct Defocus : public Event < Type::Defocus, Group::Instance + Group::Window > {
            Defocus() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
        };
        struct Maximize : public Event < Type::Maximize, Group::Instance + Group::Window > {
            Maximize() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
        };
        struct Minimize : public Event < Type::Minimize, Group::Instance + Group::Window > {
            Minimize() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
        };
        struct Restore : public Event < Type::Restore, Group::Instance + Group::Window > {
            Restore() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
        };
    } /* Window */
} /* Andromeda::System::Event */