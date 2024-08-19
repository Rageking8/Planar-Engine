#include "Planar/Engine/Component/Script.hpp"

namespace Planar::Engine::Component
{
    Script::Script(GameObject::GameObject* parent,
        bool generate_guid, const std::string& script) :
        Component(parent, generate_guid), script{ script }
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(Script, std::string, script)

    void Script::load_impl()
    {
        set_script(asset.get_script());
    }
}
