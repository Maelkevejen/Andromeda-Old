#pragma once

namespace Andromeda::System::Structure {
    template<typename Element>
    struct Duo {
        Element α, β;
        friend auto operator <=> (const Duo &, const Duo &) = default;
    };

    template<typename Element>
    struct Trio {
        Element α, β, γ;
        friend auto operator <=> (const Trio &, const Trio &) = default;
    };

    template<typename Element>
    struct Quartet {
        Element α, β, γ, δ;
        friend auto operator <=> (const Quartet &, const Quartet &) = default;
    };

    template<typename Element>
    struct Quintet {
        Element α, β, γ, δ, ε;
        friend auto operator <=> (const Quintet &, const Quintet &) = default;
    };

} /* Andromeda::System::Structure */