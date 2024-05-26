#include "Planar/Engine/Core/Utils/EnumClass/EnumClassFlags.hpp"

namespace Planar::Engine::Core::Utils::EnumClass
{
    template <Concepts::EnumClass T>
    constexpr std::underlying_type_t<T> to_underlying(T e)
    {
        return static_cast<std::underlying_type_t<T>>(e);
    }

    template <EnumClassFlag T>
    constexpr T operator|(T lhs, T rhs)
    {
        return static_cast<T>(
            to_underlying(lhs) | to_underlying(rhs));
    }

    template <EnumClassFlag T>
    constexpr bool has(T value, T test)
    {
        return to_underlying(value) & to_underlying(test);
    }
}
