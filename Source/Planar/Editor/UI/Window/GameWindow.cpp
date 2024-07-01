#include "Planar/Editor/UI/Window/GameWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ViewportScope.hpp"
#include "Planar/Engine/Graphics/OpenGL/Buffer/BufferUsage.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Primitive.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Render.hpp"
#include "Planar/Editor/Core/Editor.hpp"

#include "ThirdParty/glad/gl.h"
#include "ThirdParty/glm/gtc/matrix_transform.hpp"

PLANAR_LOAD_STD_STRING_ASSET_USING_IMPORT(
    Engine::Graphics::Shader, SpriteFrag)
PLANAR_LOAD_STD_STRING_ASSET_USING_IMPORT(
    Engine::Graphics::Shader, SpriteVert)
PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(
    Editor::Textures, DebugTexture)

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

        vbo.create({
            { 1.f, 1.f, 1.f, 1.f },
            { -1.f, 1.f, 0.f, 1.f },
            { 1.f, -1.f, 1.f, 0.f },
            { -1.f, -1.f, 0.f, 0.f } },
            Buffer::BufferUsage::STATIC_DRAW);
        vao.create(vbo);

        Shader::VertexShader vert;
        vert.create(Asset::Engine::Graphics::Shader::SpriteVert);

        Shader::FragmentShader frag;
        frag.create(Asset::Engine::Graphics::Shader::SpriteFrag);

        shader_program.create(vert, frag);

        framebuffer.create(1000, 500);

        texture.load(Asset::Editor::Textures::DebugTexture,
            Asset::Editor::Textures::DebugTexture_length);
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
        Render::color_clear({ 0.f, 0.f, 0.f, 1.f });

        glm::mat4 model = glm::mat4(1.f);
        model = glm::translate(model, { 210.f, 210.f, 0.f });
        model = glm::scale(model, { 200.f, 200.f, 1.f });

        glm::mat4 proj = glm::ortho(0.f, content_size.width,
            content_size.height, 0.f, -1.f, 1.f);
        glm::vec3 pos = { 0.f, 0.f, 0.f };
        glm::mat4 view = glm::lookAt(pos,
            pos + glm::vec3(0.f, 0.f, -1.f), { 0.f, 1.f, 0.f });

        shader_program.use();
        shader_program.set_mat4(0, model);
        shader_program.set_mat4(1, view);
        shader_program.set_mat4(2, proj);

        glActiveTexture(GL_TEXTURE0);
        texture.bind();

        vao.bind();
        Render::draw_arrays(Render::Primitive::TRIANGLE_STRIP, 0, 4);

        framebuffer.unbind();
    }
}
