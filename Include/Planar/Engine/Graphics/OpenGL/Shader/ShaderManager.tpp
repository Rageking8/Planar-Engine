#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderManager.hpp"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    template <typename ShaderProgramT>
    std::shared_ptr<ShaderProgramT> ShaderManager::get(
        const std::string& name)
    {
        if (!shader_map.contains(name))
        {
            shader_map[name] = std::make_shared<ShaderProgramT>();
        }

        return std::static_pointer_cast<ShaderProgramT>(
            shader_map[name]);
    }
}
