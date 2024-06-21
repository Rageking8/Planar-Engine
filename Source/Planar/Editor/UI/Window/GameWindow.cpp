#include "Planar/Editor/UI/Window/GameWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ViewportScope.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferUsage.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Primitive.hpp"
#include "Planar/Engine/Graphics/OpenGL/Function/Render/RenderFunction.hpp"

#include "ThirdParty/glad/gl.h"

PLANAR_LOAD_STD_STRING_ASSET_USING_IMPORT(
    Engine::Graphics::Shader, BasicFrag)
PLANAR_LOAD_STD_STRING_ASSET_USING_IMPORT(
    Engine::Graphics::Shader, BasicVert)

namespace Planar::Editor::UI::Window
{
    GameWindow::GameWindow(Core::Editor* editor) :
        EditorWindow("Game", editor)
    {

    }

    void GameWindow::init()
    {
        using namespace Planar::Engine::Graphics::OpenGL;

        set_padding({ {} });

        vbo.create({ { -0.5f, -0.5f, 0.f }, { 0.5f, -0.5f, 0.f },
            { 0.f, 0.5f, 0.f } }, Buffer::BufferUsage::STATIC_DRAW);
        vao.create(vbo);

        Shader::VertexShader vert;
        vert.create(Asset::Engine::Graphics::Shader::BasicVert);

        Shader::FragmentShader frag;
        frag.create(Asset::Engine::Graphics::Shader::BasicFrag);

        shader_program.create(vert, frag);

        framebuffer.create(1000, 500);
    }

    void GameWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        Engine::Math::Size2Df current_content_size =
            ImGui::get_content_region_avail();
        if (current_content_size != content_size)
        {
            framebuffer.resize_color_texture(
                static_cast<GLsizei>(current_content_size.width),
                static_cast<GLsizei>(current_content_size.height));
        }

        content_size = current_content_size;

        render_game();

        ImGui::image(framebuffer.get_color_texture_id(),
            content_size, true);
    }

    void GameWindow::render_game()
    {
        using namespace Planar::Engine::Graphics::OpenGL;

        Engine::Graphics::OpenGL::Core::ViewportScope
            viewport_scope(0, 0, static_cast<GLsizei>(content_size.width),
            static_cast<GLsizei>(content_size.height));

        framebuffer.bind();
        Function::Render::color_clear({ 1.f, 1.f, 1.f, 1.f });

        shader_program.use();
        vao.bind();
        Function::Render::draw_arrays(Render::Primitive::TRIANGLES,
            0, 3);

        framebuffer.unbind();
    }
}
