#include "Planar/Editor/UI/Window/GameWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Core/EditorGameMode.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Render.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ViewportScope.hpp"

namespace Planar::Editor::UI::Window
{
    GameWindow::GameWindow(Core::Editor* editor) :
        EditorWindow("Game", editor)
    {

    }

    void GameWindow::init()
    {
        set_padding({ {} });

        framebuffer.create(1000, 500);
    }

    void GameWindow::update()
    {
        auto& current_scene = editor->get_current_scene();

        if (!current_scene)
        {
            return;
        }

        if (editor->get_editor_game_mode() ==
            Core::EditorGameMode::PLAYING)
        {
            current_scene->update();
        }
        else
        {
            current_scene->editor_update();
        }
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

        editor->set_game_content_size(
            static_cast<Engine::Math::Size2Di>(content_size));

        render_game();

        ImGui::image(framebuffer.get_color_texture_id(),
            content_size, true);

        if (editor->get_current_scene() &&
            !editor->get_current_scene()->get_active_main_camera())
        {
            text_renderer.render_center_window(
                "No active camera found in scene", true);
        }
    }

    void GameWindow::render_game()
    {
        using namespace Planar::Engine::Graphics;

        OpenGL::Core::ViewportScope viewport_scope(0, 0,
            static_cast<GLsizei>(content_size.width),
            static_cast<GLsizei>(content_size.height));

        framebuffer.bind();
        OpenGL::Render::color_clear({ 0.f, 0.f, 0.f, 1.f });

        auto& current_scene = editor->get_current_scene();

        if (current_scene && editor->get_editor_game_mode() ==
            Core::EditorGameMode::PLAYING)
        {
            current_scene->render();
        }

        framebuffer.unbind();
    }
}
