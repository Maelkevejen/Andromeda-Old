#pragma once

#include <concepts>
#include <functional>
#include <string>

namespace Andromeda {
    namespace Titles {
        const std::string engine = "Andromeda";
    }  /* Titles */
    namespace Numerics {
        constexpr unsigned int Bit(unsigned int x) {
            return 1 << x;
        }
    }  /* Numerics */
    namespace Structure {
        namespace Concept {
            using Tag = void;
            template <class E>
            concept Enumeration = requires(E e) {
                std::is_enum_v<E>;
                !std::convertible_to<E, std::underlying_type<E>>;
                std::integral<std::underlying_type<E>>;
            };
        }
    }
}  /* Andromeda */