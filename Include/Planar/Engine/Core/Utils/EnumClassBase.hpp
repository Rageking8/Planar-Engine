#pragma once

#include "Planar/Engine/Core/Utils/Concepts/EnumClass.hpp"

namespace Planar::Engine::Core::Utils
{
    // Use this as a base class to add
    // member functions to an enum class
    template <Concepts::EnumClass T>
    class EnumClassBase
    {
    public:
        constexpr EnumClassBase(T init_value = {});

        constexpr operator T() const;
        constexpr explicit operator bool() const = delete;

    protected:
        T value;
    };
}

#include "Planar/Engine/Core/Utils/EnumClassBase.tpp"
