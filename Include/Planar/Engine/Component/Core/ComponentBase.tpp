#include "Planar/Engine/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"

namespace Planar::Engine::Component::Core
{
    template <typename ComponentT>
    inline std::shared_ptr<ComponentT> ComponentBase::get_component()
    {
        return get_parent()->get_component<ComponentT>();
    }
}
