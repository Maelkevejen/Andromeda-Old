#pragma once

#include "andromeda/core/core.hpp"
#include "andromeda/core/system/structure/bitmask.hpp"
#include "andromeda/core/system/structure/status.hpp"

namespace Andromeda::System::Event {
    enum class Type {
        Group = 0,
        Tick, Update, Render, Initialize, Interrupt, Execute, Terminate,
        Connect, Disconnect,
        Move, Close, Resize, Refresh, Focus, Defocus, Maximize, Minimize, Restore,
        Press, Release, Type,
        Drag, Scroll,
    };

    enum class Group {
        Undefined   = 0,
        Instance    = Andromeda::Numerics::Bit(0),
        Display     = Andromeda::Numerics::Bit(1),
        Monitor     = Andromeda::Numerics::Bit(2),
        Window      = Andromeda::Numerics::Bit(3),
        Input       = Andromeda::Numerics::Bit(4),
        Keyboard    = Andromeda::Numerics::Bit(5),
        Mouse       = Andromeda::Numerics::Bit(6),
        Controller  = Andromeda::Numerics::Bit(7),
        Button      = Andromeda::Numerics::Bit(8),
    };
    Andromeda::Structure::Concept::Tag bitmask(Andromeda::System::Event::Group);

    template<Type T, Group G>
    struct Event {};
} /* Andromeda::System::Event */