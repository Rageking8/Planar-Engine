#pragma once

#include "Planar/Engine/Core/Utils/TypeTraits/IsEnumClass.hpp"

#include <type_traits>

namespace Planar::Engine::Core::Utils::Concepts
{
    template <typename T>
    concept EnumClass =
        Planar::Engine::Core::Utils::TypeTraits::IsEnumClassV<T>;

    template <typename T>
    concept UnsignedEnumClass =
        EnumClass<T> && std::is_unsigned_v<std::underlying_type_t<T>>;
}
