#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Editor/Build/Build.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogResult.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

#include <filesystem>

namespace Planar::Editor::UI::Window
{
    BuildWindow::BuildWindow(Editor::Core::Editor* editor) :
        EditorWindow("Build", editor, false),
        build_directory_input("Build directory"),
        browse_button("Browse"),
        target_drop_down("Target:",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FIXED, 200.f },
        0.f, { "Windows 64-bit" }),
        show_console_window_checkbox("Show console window"),
        window_name_input("Window name"),
        window_size_drag("Window size:",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FIXED,
        300.f, 140.f }),
        window_maximize_checkbox("Maximize window"),
        graphics_api_drop_down("Graphics API:",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FIXED, 200.f },
        0.f, { "OpenGL 4.6" }),
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
        const Project::Project& project = editor->get_project();
        build_directory_input.set_text((project.get_root_path() /
            "Build").string());
        window_name_input.set_text(editor->get_project().
            get_project_name());
        window_size_drag.set_value({ 1280, 720 });
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

        window_name_input.render();
        window_size_drag.render();
        window_maximize_checkbox.render();
        graphics_api_drop_down.render();

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

        Engine::Core::FileSystem::SelectDialogResult result =
            Engine::Core::FileSystem::select_folder_dialog();

        if (!result)
        {
            if (result.has_error())
            {
                Engine::Core::Log::TerminalLogger::get("Editor")->
                    error(result.get_error());
            }

            return;
        }

        build_directory_input.set_text(result.get_path().string());
    }

    void BuildWindow::build()
    {
        pending_build = false;

        const Project::Project& project = editor->get_project();
        const std::filesystem::path& build_path =
            build_directory_input.get_text();
        const bool show_console_window =
            show_console_window_checkbox.get_value();
        const bool use_compression = use_compression_checkbox.
            get_value();
        const unsigned compression_level = use_compression ?
            compression_level_slider.get_value() : 0;

        application_asset.set_window_name(window_name_input.get_text());
        application_asset.set_window_size(window_size_drag.get_value());
        application_asset.set_maximize_window(window_maximize_checkbox.
            get_value());

        enter_build_mode(Build::build_dry_run(project, build_path,
            show_console_window, compression_level, application_asset));

        Build::build(project, build_path, show_console_window,
            compression_level, application_asset, {
            PLANAR_CAPTURE_THIS_PARAM2(build_progress_callback) });

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

        editor->render_main_scene_single_frame();
    }
}
