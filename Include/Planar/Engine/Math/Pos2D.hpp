#pragma once

#include "Planar/Engine/Core/Utils/Concepts/Arithmetic.hpp"

namespace Planar::Engine::Math
{
    template <Core::Utils::Concepts::Arithmetic T>
    struct Pos2D
    {
        Pos2D();
        Pos2D(T value);
        Pos2D(T x, T y);

        bool operator==(const Pos2D&) const = default;
        Pos2D& operator-(T value);

        T x;
        T y;
    };

    using Pos2Di = Pos2D<int>;
    using Pos2Du = Pos2D<unsigned>;
    using Pos2Df = Pos2D<float>;
}

#include "Planar/Engine/Math/Pos2D.tpp"
