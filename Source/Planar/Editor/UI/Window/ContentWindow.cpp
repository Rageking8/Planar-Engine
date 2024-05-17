#include "Planar/Editor/UI/Window/ContentWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/ImGuiWindowFlags.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiStyleColor.hpp"
#include "Planar/Engine/UI/ImGui/Wrapper/Group.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <vector>
#include <filesystem>

namespace Planar::Editor::UI::Window
{
    ContentWindow::ContentWindow() : folder_texture{},
        file_texture{}
    {
        set("Content",
            Planar::Engine::UI::ImGui::Window::ImGuiWindowFlags::
            ALWAYS_VERTICAL_SCROLLBAR);
    }

    void ContentWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<ImGuiWindow::Scope> result = render();

        if (!result)
        {
            return;
        }

        float window_max = ImGui::get_window_position().x +
            ImGui::get_window_content_region_max().width - 18.f;
        const float button_size = 100.f;

        ImGui::ImGuiStyleColor style_color;
        style_color.set_button_background_color({});
        style_color.set_button_hover_background_color(
            { 0.161f, 0.161f, 0.161f, 1.f });
        style_color.set_button_active_background_color(
            { 0.2f, 0.2f, 0.2f, 1.f });

        std::vector<std::filesystem::path> listing =
            Planar::Engine::Core::FileSystem::get_listing();

        for (const auto& i : listing)
        {
            {
                ImGui::Wrapper::Group group;

                std::string name = i.filename().string();

                if (std::filesystem::is_directory(i))
                {
                    ImGui::button(name, folder_texture ?
                        folder_texture->get_texture() : 0, button_size);
                }
                else if (std::filesystem::is_regular_file(i))
                {
                    ImGui::button(name, file_texture ?
                        file_texture->get_texture() : 0, button_size);
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
        Planar::Engine::Graphics::Texture::Texture& new_folder_texture)
    {
        folder_texture = &new_folder_texture;
    }

    void ContentWindow::set_file_texture(
        Planar::Engine::Graphics::Texture::Texture& new_file_texture)
    {
        file_texture = &new_file_texture;
    }
}
