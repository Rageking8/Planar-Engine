#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Component/ComponentMacros.hpp"
#include "Planar/Engine/Component/Transform2DAsset.hpp"
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

        float get_rotation() const;
        void set_rotation(float new_rotation);

        virtual Transform2DAsset& get_asset() override;

    private:
        Math::Pos2Df position;
        float rotation;
        Transform2DAsset asset;
    };
}
