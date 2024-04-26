#pragma once

#include "Planar/Engine/Core/Utils/TypeTraits/IsEnumClass.hpp"

namespace Planar::Engine::Core::Utils
{
    // Use this as a base class to add
    // member functions to an enum class
    template <typename T>
    class EnumClassBase
    {
        static_assert(
            Planar::Engine::Core::Utils::TypeTraits::IsEnumClassV<T>,
            "`T` must be an enum class");

    public:
        constexpr EnumClassBase(T init_value = {});

        constexpr operator T() const;
        constexpr explicit operator bool() const = delete;

    protected:
        T value;
    };
}

#include "Planar/Engine/Core/Utils/EnumClassBase.tpp"
