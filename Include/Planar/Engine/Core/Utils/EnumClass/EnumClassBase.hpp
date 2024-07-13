#pragma once

#include "Planar/Engine/Core/Utils/Concepts/EnumClass.hpp"

namespace Planar::Engine::Core::Utils::EnumClass
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

        int get_int() const;

    protected:
        T value;
    };
}

#include "Planar/Engine/Core/Utils/EnumClass/EnumClassBase.tpp"
