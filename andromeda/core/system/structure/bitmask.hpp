#pragma once

#include <concepts>

#include "andromeda/core/core.hpp"

namespace Andromeda::Structure::Concept {
    template <class T>
    concept Bitmask = requires(T t) {
        Enumeration<T>;
        bitmask(t);
    };
} /* Andromeda::Structure::Concept */

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
    return lhs ^ (lhs & rhs);
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr Element & operator -= (Element & lhs, Element rhs) {
    lhs = lhs - rhs;
    return lhs;
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr bool operator > (Element lhs, Element rhs) {
    using T = std::underlying_type_t<Element>;
    return static_cast<T>(lhs & rhs) > 0;
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr bool operator >= (Element lhs, Element rhs) {
    return (lhs > rhs) || (lhs == rhs);
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr bool operator == (Element lhs, Element rhs) {
    return lhs == rhs;
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr bool operator <= (Element lhs, Element rhs) {
    return (lhs < rhs) || (lhs == rhs);
}
template <Andromeda::Structure::Concept::Bitmask Element>
constexpr bool operator < (Element lhs, Element rhs) {
    using T = std::underlying_type_t<Element>;
    return static_cast<T>(lhs - rhs) == 0;
}