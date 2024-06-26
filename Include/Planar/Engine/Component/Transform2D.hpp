#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Component/ComponentMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"

namespace Planar::Engine::Component
{
    class PLANAR_API Transform2D : public Component
    {
    public:
        PLANAR_DEFINE_COMPONENT(Transform2D)

        Transform2D();

    private:
        Math::Pos2Df position;
        float rotation;
    };
}
