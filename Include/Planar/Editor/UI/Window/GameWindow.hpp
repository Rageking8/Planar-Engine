#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Graphics/OpenGL/Framebuffer/Framebuffer.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/Buffer.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/VertexArrayObject.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderProgram.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class GameWindow : public EditorWindow
    {
    public:
        GameWindow(Core::Editor* editor);

        void init();

        virtual void render_window() override;

    private:
        Engine::Math::Size2Df content_size;

        Engine::Graphics::OpenGL::Framebuffer::Framebuffer framebuffer;
        Engine::Graphics::OpenGL::Buffer::Pos2DTexArrayBuffer vbo;
        Engine::Graphics::OpenGL::Core::VertexArrayObject vao;
        Engine::Graphics::OpenGL::Shader::ShaderProgram shader_program;
        Engine::Graphics::OpenGL::Texture::Texture2D texture;

        void render_game();
    };
}
