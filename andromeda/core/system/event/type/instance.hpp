#pragma once

#include "andromeda/core/system/event/event.hpp"

namespace Andromeda::System::Event {
    template <> struct Event < Type::Update, Group::Instance + Group::Display > {
        Event() {}
    };
    template <> struct Event < Type::Update, Group::Initialize + Group::Display > {
        Event() {}
    };
    template <> struct Event < Type::Update, Group::Interrupt + Group::Display > {
        Event() {}
    };
    template <> struct Event < Type::Update, Group::Terminate + Group::Display > {
        Event() {}
    };
    namespace Instance::Display {
        using Update = Event < Type::Update, Group::Instance + Group::Display >;
        using Initialize = Event < Type::Initialize, Group::Instance + Group::Display >;
        using Interrupt = Event < Type::Interrupt, Group::Instance + Group::Display >;
        using Terminate = Event < Type::Terminate, Group::Instance + Group::Display >;
    } /* Display */
} /* Andromeda::System::Event::Instance */