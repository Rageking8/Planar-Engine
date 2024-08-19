#include "Planar/Engine/Asset/Component/ScriptAsset.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAssetMacros.hpp"
#include "Planar/Engine/Component/Script.hpp"

namespace Planar::Engine::Asset::Component
{
    ScriptAsset::ScriptAsset()
    {

    }

    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(Script,
        std::string, script, Script)

    void ScriptAsset::load_impl(Engine::Component::Script& script)
    {
        set_script(script.get_script());
    }
}
