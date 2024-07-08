#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderProgram.hpp"

#include <string>
#include <memory>
#include <unordered_map>

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    class PLANAR_API ShaderManager
    {
    public:
        ShaderManager();

        template <typename ShaderProgramT>
        std::shared_ptr<ShaderProgramT> get(const std::string& name);

    private:
        std::unordered_map<std::string, std::shared_ptr<ShaderProgram>>
            shader_map;
    };
}

#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderManager.tpp"
