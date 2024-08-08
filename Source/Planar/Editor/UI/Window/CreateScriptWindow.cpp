#include "Planar/Editor/UI/Window/CreateScriptWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Editor::Script, ComponentScript)

namespace Planar::Editor::UI::Window
{
    CreateScriptWindow::CreateScriptWindow(Editor::Core::Editor* editor) :
        EditorWindow("Create Script", editor, false),
        script_name_input("Script Name"),
        script_type_dropdown("Script Type:",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FIXED, 200.f },
        0.f, false, { "Component" }), create_button("Create"),
        pending_create{}
    {
        set_size({ { 1440.f, 810.f } });
        set_min_size({ { 500.f, 400.f } });
        set_padding({ { 24.f, 0.f } });
        set_flags(Engine::UI::ImGui::Window::WindowFlags::VIEWPORT_CENTER);
    }

    void CreateScriptWindow::update()
    {
        if (pending_create)
        {
            create();
        }
    }

    void CreateScriptWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        ImGui::Core::Cursor::set_y(60.f);

        script_name_input.render();

        const float separator_extra_height = 12.f;

        ImGui::separator(separator_extra_height);

        script_type_dropdown.render();

        ImGui::separator(separator_extra_height);

        ImGui::Core::Cursor::set_y_bottom_window(
            -separator_extra_height);
        create_button.render();
        if (create_button.is_clicked())
        {
            pending_create = true;
        }
    }

    void CreateScriptWindow::create()
    {
        pending_create = false;

        if (editor->get_script_database().create(editor->
            get_current_content_path(), script_name_input.get_text(),
            Asset::Editor::Script::ComponentScript))
        {
            set_active(false);
        }
    }
}
