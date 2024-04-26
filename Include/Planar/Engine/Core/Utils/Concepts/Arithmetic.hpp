#pragma once

#include <type_traits>

namespace Planar::Engine::Core::Utils::Concepts
{
    template <typename T>
    concept Arithmetic = std::is_arithmetic_v<T>;
}
