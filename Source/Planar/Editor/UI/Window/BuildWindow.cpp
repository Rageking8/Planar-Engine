#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Editor/Build/Build.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <string>

namespace Planar::Editor::UI::Window
{
    BuildWindow::BuildWindow() : EditorWindow("Build", false),
        build_directory_input("Build directory"),
        browse_button("Browse"),
        target_drop_down({ "Windows 64-bit" }, "Target:", 200.f),
        show_console_window_checkbox("Show console window"),
        use_compression_checkbox("Use UPX compression"),
        compression_level_slider(7, 1, 9, "Compression Level:",
        200.f),
        build_button("Build"),
        pending_browse{},
        pending_build{}
    {
        set_size({ { 1280.f, 720.f } });
        set_min_size({ { 500.f, 400.f } });
        set_flags(Engine::UI::ImGui::Window::WindowFlags::
            VIEWPORT_CENTER);
    }

    void BuildWindow::init()
    {
        if (editor)
        {
            build_directory_input.set_text((editor->get_project().
                get_root_path() / "Build").string());
        }
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
        show_console_window_checkbox.render();

        ImGui::separator(separator_extra_height);

        use_compression_checkbox.render();
        if (use_compression_checkbox.get_value())
        {
            compression_level_slider.render();
        }

        ImGui::separator(separator_extra_height);

        ImGui::Core::Cursor::set_y_bottom_window(
            -separator_extra_height);
        build_button.render();
        if (build_button.is_clicked())
        {
            pending_build = true;
        }
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

        if (editor)
        {
            Project::Project& project = editor->get_project();
            Build::build(project.get_cs_project(),
                project.get_root_path() / "Cache" / "DotnetSDK",
                build_directory_input.get_text(),
                show_console_window_checkbox.get_value());
        }
    }
}
