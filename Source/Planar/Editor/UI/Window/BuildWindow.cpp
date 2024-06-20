#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Editor/Build/Build.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

#include <filesystem>

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
        progress_display(Element::ProgressDisplay::LayoutMode::WINDOW),
        pending_browse{},
        pending_build{},
        build_mode{}
    {
        set_size({ { 1440.f, 810.f } });
        set_min_size({ { 500.f, 400.f } });
        set_padding({ { 24.f, 0.f } });
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

        ImGui::Core::Cursor::set_y(60.f);

        build_directory_input.render();
        ImGui::same_line();
        browse_button.render();
        if (!build_mode && browse_button.is_clicked())
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

        if (!build_mode)
        {
            ImGui::Core::Cursor::set_y_bottom_window(
                -separator_extra_height);
            build_button.render();
            if (build_button.is_clicked())
            {
                pending_build = true;
            }
        }
        else
        {
            progress_display.set_y_offset(48.f);
            progress_display.render();
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

        if (!editor)
        {
            return;
        }

        Project::Project& project = editor->get_project();
        const std::filesystem::path& build_path =
            build_directory_input.get_text();
        const bool show_console_window =
            show_console_window_checkbox.get_value();
        const bool use_compression = use_compression_checkbox.
            get_value();
        const unsigned compression_level = use_compression ?
            compression_level_slider.get_value() : 0;

        enter_build_mode(Build::build_dry_run(project, build_path,
            show_console_window, compression_level));

        Build::build(project, build_path, show_console_window,
            compression_level, { PLANAR_CAPTURE_THIS_ARG2(
            build_progress_callback) });

        build_mode = false;
    }

    void BuildWindow::enter_build_mode(unsigned max)
    {
        build_mode = true;
        progress_display.reset(max);
    }

    void BuildWindow::build_progress_callback(unsigned amount,
        const std::string& text)
    {
        progress_display.set(amount, text);

        if (editor)
        {
            editor->render_main_scene_single_frame();
        }
    }
}
