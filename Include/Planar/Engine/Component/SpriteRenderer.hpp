#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/Component/Mixin/Active.hpp"
#include "Planar/Engine/Asset/Component/SpriteRendererAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include "ThirdParty/glm/fwd.hpp"

#include <string>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    class PLANAR_API SpriteRenderer :
        public Core::Component<SpriteRenderer,
        Asset::Component::SpriteRendererAsset, Mixin::Active>
    {
    public:
        PLANAR_DEFINE_COMPONENT(SpriteRenderer)

        SpriteRenderer(GameObject::GameObject* parent,
            bool generate_guid = true);

        PLANAR_DECLARE_GET_SET(std::string, sprite)
        PLANAR_DECLARE_GET_SET(bool, flip_x)
        PLANAR_DECLARE_GET_SET(bool, flip_y)

    private:
        std::string sprite;
        bool flip_x;
        bool flip_y;

        glm::mat4 calc_model_mat() const;

        virtual void load_impl() override;

        virtual void render_impl() override;
    };
}
