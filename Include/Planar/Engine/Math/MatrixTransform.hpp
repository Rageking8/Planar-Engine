#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include "ThirdParty/glm/fwd.hpp"

namespace Planar::Engine::Math
{
    PLANAR_API glm::mat4 calc_view_mat(Pos2Df position);

    PLANAR_API glm::mat4 calc_projection_mat(Size2Di size,
        float scale);
}
