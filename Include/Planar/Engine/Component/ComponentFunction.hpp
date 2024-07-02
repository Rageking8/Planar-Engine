#pragma once

#include <memory>

namespace Planar::Engine::Component
{
    template <typename DerivedComponentT, typename BaseComponentT>
    DerivedComponentT* component_downcast(
        std::shared_ptr<BaseComponentT>& component);
}

#include "Planar/Engine/Component/ComponentFunction.tpp"
