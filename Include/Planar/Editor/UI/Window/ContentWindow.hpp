#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Renderer/TextRenderer.hpp"
#include "Planar/Engine/Graphics/Texture/Texture.hpp"

#include <filesystem>

namespace Planar::Editor::UI::Window
{
    class ContentWindow : public EditorWindow
    {
    public:
        ContentWindow();

        virtual void render_window() override;

        void set_root_path(const std::filesystem::path& new_root_path,
            bool reset_current_path = true);

        void set_folder_texture(
            Planar::Engine::Graphics::Texture::Texture&
            new_folder_texture);
        void set_file_texture(
            Planar::Engine::Graphics::Texture::Texture&
            new_file_texture);
        void set_left_arrow_texture(
            Planar::Engine::Graphics::Texture::Texture&
            new_left_arrow_texture);

    private:
        std::filesystem::path root_path;
        std::filesystem::path current_path;

        Planar::Engine::Graphics::Texture::Texture* folder_texture;
        Planar::Engine::Graphics::Texture::Texture* file_texture;
        Planar::Engine::Graphics::Texture::Texture* left_arrow_texture;

        Planar::Engine::UI::ImGui::Renderer::TextRenderer text_renderer;

        void render_menu_bar();
    };
}
