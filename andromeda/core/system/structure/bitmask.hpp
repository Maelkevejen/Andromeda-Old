#pragma once

#include "andromeda/core/core.hpp"

#include <concepts>

namespace Andromeda::Structure::Concept {
    template <class T>
    concept Bitmask = requires(T t) {
        Enumeration<T>;
        {
            bitmask(t)
        }
        -> std::same_as<Andromeda::Structure::Concept::Tag>;
    };
} /* Andromeda::Structure::Concept */

template <Andromeda::Structure::Concept::Bitmask Element>
constexpr bool operator >> (Element lhs, Element rhs) {
    using T = std::underlying_type_t<Element>;
    return (static_cast<Element>(static_cast<T>(lhs) & static_cast<T>(rhs)) == rhs);
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr bool operator << (Element lhs, Element rhs) {
    using T = std::underlying_type_t<Element>;
    return (static_cast<Element>(static_cast<T>(rhs) & static_cast<T>(lhs)) == lhs);
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element operator & (Element lhs, Element rhs) {
    using T = std::underlying_type_t<Element>;
    return static_cast<Element>(static_cast<T>(lhs) & static_cast<T>(rhs));
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element & operator &= (Element & lhs, Element rhs) {
    lhs = lhs & rhs;
    return lhs;
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element operator + (Element lhs, Element rhs) {
    using T = std::underlying_type_t<Element>;
    return static_cast<Element>(static_cast<T>(lhs) | static_cast<T>(rhs));
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element & operator += (Element & lhs, Element rhs) {
    lhs = lhs + rhs;
    return lhs;
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element operator ^ (Element lhs, Element rhs) {
    using T = std::underlying_type_t<Element>;
    return static_cast<Element>(static_cast<T>(lhs) ^ static_cast<T>(rhs));
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element & operator ^= (Element & lhs, Element rhs) {
    lhs = lhs ^ rhs;
    return lhs;
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element operator - (Element lhs, Element rhs) {
    using T = std::underlying_type_t<Element>;
    return lhs ^ static_cast<Element>(static_cast<T>(lhs) & static_cast<T>(rhs));
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element & operator -= (Element & lhs, Element rhs) {
    lhs = lhs - rhs;
    return lhs;
}