#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
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

        PLANAR_DECLARE_GET_SET(Math::Pos2Df, position)
        PLANAR_DECLARE_GET_SET(float, rotation)
        PLANAR_DECLARE_GET_SET(Math::Size2Df, scale)

    private:
        virtual void load_impl(
            Engine::Component::Transform2D& transform) override;
    };
}
