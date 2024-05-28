#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <string>

namespace Planar::Editor::UI::Window
{
    BuildWindow::BuildWindow() : EditorWindow("Build", false),
        build_directory_input("Build directory"),
        browse_button("Browse"), build_button("Build"),
        pending_browse{}
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

    void BuildWindow::update()
    {
        if (pending_browse)
        {
            browse();
        }
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
        if (browse_button.is_clicked())
        {
            pending_browse = true;
        }

        ImGui::cursor_y_bottom_window();
        build_button.render();
    }

    void BuildWindow::set_root_path(
        const std::filesystem::path& new_root_path)
    {
        root_path = new_root_path;
    }

    void BuildWindow::browse()
    {
        pending_browse = false;

        std::wstring directory =
            Engine::Core::FileSystem::select_folder_dialog();

        if (!directory.empty())
        {
            build_directory_input.set_text(
                { directory.begin(), directory.end() });
        }
        else
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("Invalid directory");
        }
    }
}
