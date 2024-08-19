#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Asset/Component/Mixin/Active.hpp"

#include <string>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Script)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API ScriptAsset : public Core::ComponentAsset<
        Engine::Component::Script, Mixin::Active>
    {
    public:
        ScriptAsset();

        PLANAR_DECLARE_GET_SET(std::string, script)

    private:
        virtual void load_impl(Engine::Component::Script& script)
            override;
    };
}
