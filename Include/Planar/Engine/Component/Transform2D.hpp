#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Component/ComponentMacros.hpp"
#include "Planar/Engine/Asset/Component/Transform2DAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    class PLANAR_API Transform2D : public Component
    {
    public:
        PLANAR_DEFINE_COMPONENT(Transform2D)

        Transform2D(GameObject::GameObject* parent,
            bool generate_guid = true);

        void load();
        void load(YAML::Node node);

        Math::Pos2Df get_position() const;
        void set_position(Math::Pos2Df new_position);

        void translate(Math::Size2Df delta);
        void translate_x(float delta);
        void translate_y(float delta);

        float get_rotation() const;
        void set_rotation(float new_rotation);

        Math::Size2Df get_scale() const;
        void set_scale(Math::Size2Df new_scale);

        virtual Asset::Component::Transform2DAsset& get_asset()
            override;

    private:
        Math::Pos2Df position;
        float rotation;
        Math::Size2Df scale;
        Asset::Component::Transform2DAsset asset;
    };
}
