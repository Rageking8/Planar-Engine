#include "Planar/Editor/UI/Window/ContentWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleColor.hpp"
#include "Planar/Engine/UI/ImGui/Wrapper/Group.hpp"
#include "Planar/Engine/UI/ImGui/Menu/WindowMenuBar.hpp"
#include "Planar/Engine/Audio/Audio.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Asset/AssetDatabase.hpp"

#include <vector>
#include <memory>

#define PLANAR_ASSET_DRAG_DROP_SOURCE(name, ns)      \
    ImGui::drag_drop_source(#name "Asset", &editor-> \
        get_asset_database()->                       \
        get_owning_asset<Engine::ns::name>(          \
        Engine::Asset::get_guid(i))->get_guid());    \

namespace Planar::Editor::UI::Window
{
    ContentWindow::ContentWindow(Editor::Core::Editor* editor) :
        EditorWindow("Content", editor),
        folder_texture{}, file_texture{}, left_arrow_texture{}
    {
        using namespace Engine::Core::Utils::EnumClass;

        set_flags(Engine::UI::ImGui::Window::WindowFlags::
            ALWAYS_VERTICAL_SCROLLBAR |
            Engine::UI::ImGui::Window::WindowFlags::
            MENU_BAR);
    }

    void ContentWindow::init()
    {
        editor->set_current_content_path(editor->get_project().
            get_root_path());

        back_button.set_size(15.f);
        back_button.set("Back", left_arrow_texture->get_id());
    }

    void ContentWindow::render_window()
    {
        using namespace Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        render_menu_bar();

        float window_max = ImGui::get_cursor_screen_pos().x +
            ImGui::get_content_region_avail().width - 18.f;
        const float button_size = 100.f;

        ImGui::Style::StyleColor style_color;
        style_color.set_button_background_color({});
        style_color.set_button_hover_background_color(
            { 0.161f, 0.161f, 0.161f, 1.f });
        style_color.set_button_active_background_color(
            { 0.2f, 0.2f, 0.2f, 1.f });

        std::vector<std::filesystem::path> listing =
            Planar::Engine::Core::FileSystem::get_listing(
            editor->get_current_content_path());

        for (const auto& i : listing)
        {
            {
                ImGui::Wrapper::Group group;

                std::string name = i.filename().string();
                bool is_directory = std::filesystem::is_directory(i);
                bool is_regular_file =
                    std::filesystem::is_regular_file(i);

                ImGui::Element::Button::Button button;
                button.set_size(button_size);

                if (is_directory)
                {
                    button.set(name, folder_texture ? folder_texture->
                        get_id() : 0);
                }
                else if (is_regular_file)
                {
                    button.set(name, file_texture ? file_texture->
                        get_id() : 0);
                }

                button.render();
                if (button.is_left_double_clicked())
                {
                    if (is_directory)
                    {
                        editor->set_current_content_path(i);
                    }

                    content_double_click(i);
                }
                else if (button.is_clicked())
                {
                    content_single_click(name);
                }

                if (is_regular_file && i.extension() == ".planarsprite")
                {
                    PLANAR_ASSET_DRAG_DROP_SOURCE(Sprite, Core::Sprite)
                }
                else if (is_regular_file && i.extension() == ".planaraudio")
                {
                    PLANAR_ASSET_DRAG_DROP_SOURCE(Audio, Audio)
                }

                text_renderer.render_center_truncate(name, button_size,
                    -7.5f, 2);
            }

            float last_btn = ImGui::get_item_rect_max().x;
            float next_btn = last_btn + ImGui::get_item_spacing().width +
                button_size;

            if (next_btn < window_max)
            {
                ImGui::same_line();
            }
        }
    }

    void ContentWindow::set_folder_texture(
        Engine::Graphics::OpenGL::Texture::Texture2D&
        new_folder_texture)
    {
        folder_texture = &new_folder_texture;
    }

    void ContentWindow::set_file_texture(
        Planar::Engine::Graphics::OpenGL::Texture::Texture2D&
        new_file_texture)
    {
        file_texture = &new_file_texture;
    }

    void ContentWindow::set_left_arrow_texture(
        Engine::Graphics::OpenGL::Texture::Texture2D&
        new_left_arrow_texture)
    {
        left_arrow_texture = &new_left_arrow_texture;
    }

    void ContentWindow::render_menu_bar()
    {
        using namespace Engine::UI;

        ImGui::Menu::WindowMenuBar menu_bar;
        if (menu_bar.start())
        {
            back_button.render();
            if (back_button.is_clicked())
            {
                const std::filesystem::path current_path =
                    editor->get_current_content_path();

                if (current_path.has_parent_path() &&
                    !std::filesystem::equivalent(current_path,
                    editor->get_project().get_root_path()))
                {
                    editor->set_current_content_path(current_path.
                        parent_path());
                }
            }
        }
    }

    void ContentWindow::content_single_click(const std::string& name)
    {
        editor->get_select_handler().select_content(name);
    }

    void ContentWindow::content_double_click(
        const std::filesystem::path& path)
    {
        if (std::filesystem::is_regular_file(path) &&
            path.extension() == ".planarscene")
        {
            editor->new_current_scene(path);
        }
    }
}
