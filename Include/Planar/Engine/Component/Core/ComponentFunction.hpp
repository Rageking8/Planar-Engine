#pragma once

#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component::Core , ComponentBase)

namespace Planar::Engine::Component::Core
{
    template <typename DerivedComponentT>
    DerivedComponentT* component_downcast(
        std::shared_ptr<ComponentBase>& component);
}

#include "Planar/Engine/Component/Core/ComponentFunction.tpp"
