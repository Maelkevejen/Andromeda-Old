#pragma once

#include "andromeda/core/system/event/event.hpp"
#include "andromeda/core/system/structure/tuple.hpp"

namespace Andromeda::System::Event {
    namespace Monitor {
        struct Connect : Event < Type::Connect, Group::Instance + Group::Monitor > {};
        struct Disconnect : Event < Type::Scroll, Group::Instance + Group::Monitor > {};
    } /* Mouse */
} /* Andromeda::System::Event */