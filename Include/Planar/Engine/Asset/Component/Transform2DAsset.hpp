#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Transform2D)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API Transform2DAsset : public Asset
    {
    public:
        Transform2DAsset();

        void load(Engine::Component::Transform2D& transform);

        std::string get_guid() const;

        Math::Pos2Df get_position() const;
        void set_position(Math::Pos2Df new_position);

        float get_rotation() const;
        void set_rotation(float new_rotation);
    };
}
