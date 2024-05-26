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
}
