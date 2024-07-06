#include "Planar/Engine/Component/Core/ComponentFunction.hpp"
#include "Planar/Engine/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/Utils/Cast/Cast.hpp"

namespace Planar::Engine::Component::Core
{
    template <typename DerivedComponentT>
    inline DerivedComponentT* component_downcast(
        std::shared_ptr<ComponentBase>& component)
    {
        PLANAR_ASSERT(
            component->get_type() == DerivedComponentT::TYPE,
            "`component` has wrong type");

        return Engine::Core::Utils::Cast::shared_ptr_downcast
            <DerivedComponentT>(component);
    }
}
