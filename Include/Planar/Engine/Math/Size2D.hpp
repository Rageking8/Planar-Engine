#pragma once

#include "Planar/Engine/Core/Utils/Arithmetic.hpp"

namespace Planar::Engine::Math
{
    template <Arithmetic T>
    struct Size2D
    {
        T width{};
        T height{};
    };

    using Size2Di = Size2D<int>;
    using Size2Du = Size2D<unsigned>;
    using Size2Df = Size2D<float>;
}
