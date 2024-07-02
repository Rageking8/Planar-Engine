#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Asset/Component/ComponentAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Transform2D)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API Transform2DAsset :
        public ComponentAsset<Engine::Component::Transform2D>
    {
    public:
        Transform2DAsset();

        Math::Pos2Df get_position() const;
        void set_position(Math::Pos2Df new_position);

        float get_rotation() const;
        void set_rotation(float new_rotation);

    private:
        virtual void load_impl(
            Engine::Component::Transform2D& transform) override;
    };
}
