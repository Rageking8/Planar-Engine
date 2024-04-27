#pragma once

#include "Planar/Engine/Core/Utils/TypeTraits/IsEnumClass.hpp"

namespace Planar::Engine::Core::Utils::Concepts
{
    template <typename T>
    concept EnumClass =
        Planar::Engine::Core::Utils::TypeTraits::IsEnumClassV<T>;
}
