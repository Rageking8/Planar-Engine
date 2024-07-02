#pragma once

#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Component)

namespace Planar::Engine::Component
{
    template <typename DerivedComponentT>
    DerivedComponentT* component_downcast(
        std::shared_ptr<Component>& component);
}

#include "Planar/Engine/Component/ComponentFunction.tpp"
