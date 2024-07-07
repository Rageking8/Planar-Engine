#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Asset/Component/Mixin/Active.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, SpriteRenderer)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API SpriteRendererAsset :
        public Core::ComponentAsset<Engine::Component::SpriteRenderer,
        Mixin::Active>
    {
    public:
        SpriteRendererAsset();

    private:
        virtual void load_impl(
            Engine::Component::SpriteRenderer& sprite_renderer)
            override;
    };
}
