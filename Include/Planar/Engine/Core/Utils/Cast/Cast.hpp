#pragma once

#include "Planar/Engine/Core/Utils/Concepts/Downcast.hpp"
#include "Planar/Engine/Core/Utils/Concepts/Polymorphic.hpp"

#include <memory>

namespace Planar::Engine::Core::Utils::Cast
{
    template <typename Derived, Concepts::Polymorphic Base>
        requires Concepts::Downcast<Derived, Base>
    Derived* unique_ptr_downcast(std::unique_ptr<Base>& pointer);

    template <typename Derived, Concepts::Polymorphic Base>
        requires Concepts::Downcast<Derived, Base>
    Derived* shared_ptr_downcast(std::shared_ptr<Base>& pointer);
}

#include "Planar/Engine/Core/Utils/Cast/Cast.tpp"
