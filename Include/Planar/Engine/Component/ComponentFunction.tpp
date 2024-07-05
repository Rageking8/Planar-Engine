#include "Planar/Engine/Component/ComponentFunction.hpp"
#include "Planar/Engine/Component/ComponentBase.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/Utils/Cast/Cast.hpp"

namespace Planar::Engine::Component
{
    template <typename DerivedComponentT>
    inline DerivedComponentT* component_downcast(
        std::shared_ptr<ComponentBase>& component)
    {
        PLANAR_ASSERT(
            component->get_type() == DerivedComponentT::TYPE,
            "`component` has wrong type");

        return Core::Utils::Cast::shared_ptr_downcast
            <DerivedComponentT>(component);
    }
}
