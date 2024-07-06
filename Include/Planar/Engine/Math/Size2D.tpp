#include "Planar/Engine/Math/Size2D.hpp"

namespace Planar::Engine::Math
{
    template <Core::Utils::Concepts::Arithmetic T>
    inline Size2D<T>::Size2D() : width{}, height{}
    {

    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline Size2D<T>::Size2D(T size) :
        width{ size }, height{ size }
    {

    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline Size2D<T>::Size2D(T width, T height) :
        width{ width }, height{ height }
    {

    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline Size2D<T>::Size2D(std::array<T, 2> array) :
        width{ array[0] }, height{ array[1] }
    {

    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline bool Size2D<T>::operator==(const Size2D<T>& other) const
    {
        return width == other.width && height == other.height;
    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline std::array<T, 2> Size2D<T>::get_array() const
    {
        return { width, height };
    }
}
