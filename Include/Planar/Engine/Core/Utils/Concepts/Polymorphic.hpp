#pragma once

#include <type_traits>

namespace Planar::Engine::Core::Utils::Concepts
{
    template <typename T>
    concept Polymorphic = std::is_polymorphic_v<T>;
}
