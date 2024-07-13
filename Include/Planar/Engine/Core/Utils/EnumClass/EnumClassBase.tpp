#include "Planar/Engine/Core/Utils/EnumClass/EnumClassBase.hpp"

namespace Planar::Engine::Core::Utils::EnumClass
{
    template <Concepts::EnumClass T>
    inline constexpr EnumClassBase<T>::EnumClassBase(T init_value) :
        value{ init_value }
    {

    }

    template <Concepts::EnumClass T>
    inline constexpr EnumClassBase<T>::operator T() const
    {
        return value;
    }

    template <Concepts::EnumClass T>
    inline int EnumClassBase<T>::get_int() const
    {
        return static_cast<int>(value);
    }
}
