#include "Planar/Engine/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Scene/Scene.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component::Core
{
    ComponentBase::ComponentBase(GameObject::GameObject* parent,
        bool generate_guid) : parent{ parent }
    {
        if (generate_guid)
        {
            guid = Engine::Core::GUID::generate_guid(
                Engine::Core::GUID::Representation::DEFAULT_COMPACT);
        }
    }

    ComponentBase::~ComponentBase()
    {

    }

    bool ComponentBase::match(ComponentType other) const
    {
        return other == TYPE;
    }

    std::string ComponentBase::get_guid() const
    {
        return guid;
    }

    void ComponentBase::set_guid(const std::string& new_guid)
    {
        guid = new_guid;
    }

    GameObject::GameObject* ComponentBase::get_parent() const
    {
        return parent;
    }

    void ComponentBase::set_parent(GameObject::GameObject* new_parent)
    {
        parent = new_parent;
    }

    std::shared_ptr<Transform2D> ComponentBase::get_transform() const
    {
        return get_parent()->get_transform();
    }

    std::shared_ptr<Camera2D> ComponentBase::get_active_main_camera()
        const
    {
        return get_parent()->get_scene()->get_active_main_camera();
    }

    YAML::Node ComponentBase::get_node() const
    {
        return get_asset().get_asset();
    }

    Engine::Core::Input::InputController&
        ComponentBase::get_input_controller()
    {
        return get_parent()->get_scene()->
            get_application()->get_input_controller();
    }
}
