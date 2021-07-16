#pragma once

#include "andromeda/core/core.hpp"
#include "andromeda/core/system/structure/bitmask.hpp"
#include "andromeda/core/system/structure/status.hpp"

namespace Andromeda::System::Event {
    enum class Type {
        Group = 0,
        Tick, Update, Render, Terminate,
        Connect, Disconnect,
        Move, Close, Resize, Refresh, Focus, Defocus, Maximize, Minimize, Restore,
        Press, Release, Type,
        Scroll,
    };

    enum class Group {
        Undefined   = 0,
        Instance    = Andromeda::Numerics::Bit(0),
        Monitor     = Andromeda::Numerics::Bit(1),
        Window      = Andromeda::Numerics::Bit(2),
        Input       = Andromeda::Numerics::Bit(3),
        Keyboard    = Andromeda::Numerics::Bit(4),
        Mouse       = Andromeda::Numerics::Bit(5),
        Controller  = Andromeda::Numerics::Bit(6),
        Button      = Andromeda::Numerics::Bit(7),
    };
    Andromeda::Structure::Concept::Tag bitmask(Andromeda::System::Event::Group);

    template<Type T, Group G>
    struct Event {

    };
} /* Andromeda::System::Event */