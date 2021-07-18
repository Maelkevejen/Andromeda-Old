#pragma once

#include "andromeda/core/system/event/event.hpp"

namespace Andromeda::System::Event::Instance {
    namespace Display {
        struct Update : public Event < Type::Update, Group::Instance + Group::Display > {
            Update() {}
        };
        struct Initialize : public Event < Type::Initialize, Group::Instance + Group::Display > {
            Initialize() {}
        };
        struct Interrupt : public Event < Type::Interrupt, Group::Instance + Group::Display > {
            Interrupt() {}
        };
        struct Terminate : public Event < Type::Terminate, Group::Instance + Group::Display > {
            Terminate() {}
        };
    } /* Display */
} /* Andromeda::System::Event::Instance */