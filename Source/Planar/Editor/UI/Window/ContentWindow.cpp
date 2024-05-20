#include "Planar/Editor/UI/Window/ContentWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleColor.hpp"
#include "Planar/Engine/UI/ImGui/Wrapper/Group.hpp"
#include "Planar/Engine/UI/ImGui/Menu/WindowMenuBar.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <vector>

namespace Planar::Editor::UI::Window
{
    ContentWindow::ContentWindow() : folder_texture{},
        file_texture{}, left_arrow_texture{}
    {
        using namespace Planar::Engine::Core::Utils;

        set("Content",
            Planar::Engine::UI::ImGui::Window::WindowFlags::
            ALWAYS_VERTICAL_SCROLLBAR |
            Planar::Engine::UI::ImGui::Window::WindowFlags::
            MENU_BAR);
    }

    void ContentWindow::init()
    {
        back_button.set("Back", 15.f, left_arrow_texture->get_texture());
    }

    void ContentWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        render_menu_bar();

        float window_max = ImGui::get_window_position().x +
            ImGui::get_window_content_region_max().width - 18.f;
        const float button_size = 100.f;

        ImGui::Style::StyleColor style_color;
        style_color.set_button_background_color({});
        style_color.set_button_hover_background_color(
            { 0.161f, 0.161f, 0.161f, 1.f });
        style_color.set_button_active_background_color(
            { 0.2f, 0.2f, 0.2f, 1.f });

        std::vector<std::filesystem::path> listing =
            Planar::Engine::Core::FileSystem::get_listing(
            current_path);

        for (const auto& i : listing)
        {
            {
                ImGui::Wrapper::Group group;

                std::string name = i.filename().string();
                bool is_directory = std::filesystem::is_directory(i);
                bool is_regular_file =
                    std::filesystem::is_regular_file(i);

                ImGui::Element::Button button;

                if (is_directory)
                {
                    button.set(name, button_size, folder_texture ?
                        folder_texture->get_texture() : 0);
                }
                else if (is_regular_file)
                {
                    button.set(name, button_size, file_texture ?
                        file_texture->get_texture() : 0);
                }

                button.render();
                if (button.is_left_double_clicked())
                {
                    if (is_directory)
                    {
                        current_path = i;
                    }
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

    void ContentWindow::set_root_path(
        const std::filesystem::path& new_root_path,
        bool reset_current_path)
    {
        root_path = new_root_path;

        if (reset_current_path)
        {
            current_path = root_path;
        }
    }

    void ContentWindow::set_folder_texture(
        Planar::Engine::Graphics::Texture::Texture&
        new_folder_texture)
    {
        folder_texture = &new_folder_texture;
    }

    void ContentWindow::set_file_texture(
        Planar::Engine::Graphics::Texture::Texture&
        new_file_texture)
    {
        file_texture = &new_file_texture;
    }

    void ContentWindow::set_left_arrow_texture(
        Planar::Engine::Graphics::Texture::Texture&
        new_left_arrow_texture)
    {
        left_arrow_texture = &new_left_arrow_texture;
    }

    void ContentWindow::render_menu_bar()
    {
        using namespace Planar::Engine::UI;

        ImGui::Menu::WindowMenuBar menu_bar;
        if (menu_bar.start())
        {
            back_button.render();
            if (back_button.is_clicked())
            {
                if (current_path.has_parent_path() &&
                    !std::filesystem::equivalent(current_path, root_path))
                {
                    current_path = current_path.parent_path();
                }
            }
        }
    }
}
