#pragma once

#include <type_traits>

namespace Planar::Engine::Core::Utils::TypeTraits
{
    template <typename T, bool B = std::is_enum_v<T>>
    struct IsEnumClass : std::false_type
    {

    };

    template <typename T>
    struct IsEnumClass<T, true> : std::integral_constant<bool,
        !std::is_convertible_v<T, std::underlying_type_t<T>>>
    {

    };

    template <typename T>
    inline constexpr bool IsEnumClassV = IsEnumClass<T>::value;
}
