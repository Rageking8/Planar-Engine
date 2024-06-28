#pragma once

#include "Planar/Engine/Core/Utils/Concepts/Polymorphic.hpp"

#include <concepts>

namespace Planar::Engine::Core::Utils::Cast
{
    template <typename Derived, Concepts::Polymorphic Base>
        requires std::derived_from<Derived, Base> &&
        (!std::same_as<Derived, Base>)
    Derived* unique_ptr_downcast(std::unique_ptr<Base>& pointer);
}

#include "Planar/Engine/Core/Utils/Cast/Cast.tpp"
