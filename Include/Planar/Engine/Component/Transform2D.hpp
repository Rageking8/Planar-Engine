#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/Asset/Component/Transform2DAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include "ThirdParty/glm/fwd.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    class PLANAR_API Transform2D :
        public Core::Component<Transform2D,
        Asset::Component::Transform2DAsset>
    {
    public:
        PLANAR_DEFINE_COMPONENT(Transform2D)

        Transform2D(GameObject::GameObject* parent,
            bool generate_guid = true);

        PLANAR_DECLARE_GET_SET(Math::Pos2Df, position)

        void translate(Math::Size2Df delta);
        void translate_x(float delta);
        void translate_y(float delta);

        PLANAR_DECLARE_GET_SET(float, rotation)
        PLANAR_DECLARE_GET_SET(Math::Size2Df, scale)

        glm::mat4 get_model_mat() const;

    private:
        Math::Pos2Df position;
        float rotation;
        Math::Size2Df scale;

        virtual void load_impl() override;
    };
}
