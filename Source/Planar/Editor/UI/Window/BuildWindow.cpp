#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"

namespace Planar::Editor::UI::Window
{
    BuildWindow::BuildWindow() : EditorWindow("Build", false),
        build_directory_input("Build directory"),
        browse_button("Browse"), build_button("Build")
    {
        set_size({ { 1280.f, 720.f } });
        set_min_size({ { 500.f, 200.f } });
        set_flags(Engine::UI::ImGui::Window::WindowFlags::
            VIEWPORT_CENTER);
    }

    void BuildWindow::init()
    {
        build_directory_input.set_text((root_path / "Build").
            string());
    }

    void BuildWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        build_directory_input.render();
        ImGui::same_line();
        browse_button.render();

        ImGui::newline(5);

        ImGui::cursor_y_bottom_window();
        build_button.render();
    }

    void BuildWindow::set_root_path(
        const std::filesystem::path& new_root_path)
    {
        root_path = new_root_path;
    }
}
