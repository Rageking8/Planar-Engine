#pragma once

#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, ComponentBase)

namespace Planar::Engine::Component
{
    template <typename DerivedComponentT>
    DerivedComponentT* component_downcast(
        std::shared_ptr<ComponentBase>& component);
}

#include "Planar/Engine/Component/ComponentFunction.tpp"
