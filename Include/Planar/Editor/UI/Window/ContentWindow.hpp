#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Renderer/TextRenderer.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"

#include <string>
#include <filesystem>
#include <functional>

namespace Planar::Editor::UI::Window
{
    class ContentWindow : public EditorWindow
    {
    public:
        ContentWindow();

        void init();

        virtual void render_window() override;

        void set_folder_texture(
            Engine::Graphics::OpenGL::Texture::Texture2D&
            new_folder_texture);
        void set_file_texture(
            Engine::Graphics::OpenGL::Texture::Texture2D&
            new_file_texture);
        void set_left_arrow_texture(
            Engine::Graphics::OpenGL::Texture::Texture2D&
            new_left_arrow_texture);

        void set_select_callback(
            const std::function<void(const std::string&)>&
            new_select_callback);

    private:
        std::filesystem::path current_path;

        Engine::Graphics::OpenGL::Texture::Texture2D* folder_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D* file_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D* left_arrow_texture;

        Engine::UI::ImGui::Renderer::TextRenderer text_renderer;

        Engine::UI::ImGui::Element::Button back_button;

        std::function<void(const std::string&)> select_callback;

        void render_menu_bar();

        void content_single_click(const std::string& name);
        void content_double_click(const std::filesystem::path& path);
    };
}
