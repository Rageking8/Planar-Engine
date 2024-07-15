#include "Planar/Engine/Math/MatrixTransform.hpp"

#include "ThirdParty/glm/vec3.hpp"
#include "ThirdParty/glm/mat4x4.hpp"
#include "ThirdParty/glm/gtc/matrix_transform.hpp"

#include <limits>

namespace Planar::Engine::Math
{
    glm::mat4 calc_view_mat(Pos2Df position)
    {
        const glm::vec3 pos{ position.x, position.y, 0.f };

        return glm::lookAt(pos, pos + glm::vec3(0.f, 0.f, -1.f),
            { 0.f, 1.f, 0.f });
    }

    glm::mat4 calc_projection_mat(Size2Di size, float scale)
    {
        const Math::Size2Df framebuffer_size =
            static_cast<Math::Size2Df>(size);

        const float half_width = scale == 0.f ?
            std::numeric_limits<float>::infinity() :
            framebuffer_size.width / scale * 0.5f;
        const float half_height = scale == 0.f ?
            std::numeric_limits<float>::infinity() :
            framebuffer_size.height / scale * 0.5f;

        return glm::ortho(-half_width, half_width, -half_height,
            half_height, -1.f, 1.f);
    }
}
