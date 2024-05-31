#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Editor/Build/Build.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <string>

namespace Planar::Editor::UI::Window
{
    BuildWindow::BuildWindow() : EditorWindow("Build", false),
        build_directory_input("Build directory"),
        browse_button("Browse"), target_drop_down({ "Windows 64-bit" },
        "Target:", 200.f), build_button("Build"), pending_browse{},
        pending_build{}
    {
        set_size({ { 1280.f, 720.f } });
        set_min_size({ { 500.f, 300.f } });
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

        if (pending_build)
        {
            build();
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

        const float separator_extra_height = 12.f;

        ImGui::separator(separator_extra_height);

        target_drop_down.render();

        ImGui::separator(separator_extra_height);

        ImGui::cursor_y_bottom_window(
            -separator_extra_height * 2.f - 6.f);
        build_button.render();
        if (build_button.is_clicked())
        {
            pending_build = true;
        }
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

    void BuildWindow::build()
    {
        pending_build = false;

        Build::build(root_path, root_path / "Cache" / "DotnetSDK",
            build_directory_input.get_text());
    }
}
