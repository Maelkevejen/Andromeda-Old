#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/structure/tuple.hpp"

namespace Andromeda::System::Event {
    namespace Monitor {
        struct Connect : public Event < Type::Connect, Group::Instance + Group::Monitor > {
            Connect() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
            Connect(Andromeda::System::Structure::Status::Event status) : Event({status}) {}
        };
        struct Disconnect : public Event < Type::Scroll, Group::Instance + Group::Monitor > {
            Disconnect() : Event({Andromeda::System::Structure::Status::Event::Unused}) {}
            Disconnect(Andromeda::System::Structure::Status::Event status) : Event({status}) {}
        };
    } /* Monitor */
} /* Andromeda::System::Event */