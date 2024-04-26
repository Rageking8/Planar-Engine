#pragma once

#include "Planar/Engine/Core/Utils/Concepts/Arithmetic.hpp"

namespace Planar::Engine::Math
{
    template <Planar::Engine::Core::Utils::Concepts::Arithmetic T>
    struct Size2D
    {
        T width{};
        T height{};
    };

    using Size2Di = Size2D<int>;
    using Size2Du = Size2D<unsigned>;
    using Size2Df = Size2D<float>;
}
