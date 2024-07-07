#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/Component/Mixin/Active.hpp"
#include "Planar/Engine/Asset/Component/Camera2DAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include "ThirdParty/glm/fwd.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    class PLANAR_API Camera2D :
        public Core::Component<Camera2D, Asset::Component::Camera2DAsset,
        Mixin::Active>
    {
    public:
        PLANAR_DEFINE_COMPONENT(Camera2D)

        Camera2D(GameObject::GameObject* parent,
            bool generate_guid = true);

        glm::mat4 get_view_mat() const;

    private:
        virtual void load_impl() override;
    };
}
