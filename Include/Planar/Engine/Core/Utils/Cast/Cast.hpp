#pragma once

#include "Planar/Engine/Core/Utils/Concepts/Downcast.hpp"
#include "Planar/Engine/Core/Utils/Concepts/Polymorphic.hpp"

namespace Planar::Engine::Core::Utils::Cast
{
    template <typename Derived, Concepts::Polymorphic Base>
        requires Concepts::Downcast<Derived, Base>
    Derived* unique_ptr_downcast(std::unique_ptr<Base>& pointer);
}

#include "Planar/Engine/Core/Utils/Cast/Cast.tpp"
