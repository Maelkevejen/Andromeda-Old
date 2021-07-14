#pragma once

#include <concepts>
#include <functional>
#include <memory>
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
            struct Tag {};
            template <class E>
            concept Enumeration = requires(E e) {
                std::is_enum_v<E>;
                !std::convertible_to<E, std::underlying_type<E>>;
                std::integral<std::underlying_type<E>>;
            };
        }
        template<class Parameter>
        using Callback = std::function<void (Parameter &)>;
    }
}  /* Andromeda */