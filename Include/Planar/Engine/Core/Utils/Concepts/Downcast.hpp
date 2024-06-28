#pragma once

#include <concepts>

namespace Planar::Engine::Core::Utils::Concepts
{
    template <typename Derived, typename Base>
    concept Downcast = std::derived_from<Derived, Base> &&
        (!std::same_as<Derived, Base>);
}
