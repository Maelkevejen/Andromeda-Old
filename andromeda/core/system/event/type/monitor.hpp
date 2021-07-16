#pragma once

#include "andromeda/core/system/event/event.hpp"

namespace Andromeda::System::Event {
    namespace Monitor {
        struct Connect : public Event < Type::Connect, Group::Instance + Group::Monitor > {

        };
        struct Disconnect : public Event < Type::Scroll, Group::Instance + Group::Monitor > {

        };
    } /* Monitor */
} /* Andromeda::System::Event */