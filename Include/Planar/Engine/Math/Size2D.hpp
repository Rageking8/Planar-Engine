#pragma once

#include "Planar/Engine/Core/Utils/Concepts/Arithmetic.hpp"

#include <array>

namespace Planar::Engine::Math
{
    template <Core::Utils::Concepts::Arithmetic T>
    struct Size2D
    {
        Size2D();
        Size2D(T size);
        Size2D(T width, T height);
        Size2D(std::array<T, 2> array);

        bool operator==(const Size2D&) const;

        std::array<T, 2> get_array() const;

        union
        {
            T width;
            T first;
        };

        union
        {
            T height;
            T second;
        };
    };

    using Size2Di = Size2D<int>;
    using Size2Du = Size2D<unsigned>;
    using Size2Df = Size2D<float>;
}

#include "Planar/Engine/Math/Size2D.tpp"
