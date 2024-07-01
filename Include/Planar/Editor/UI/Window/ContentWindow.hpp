#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/UI/ImGui/Renderer/TextRenderer.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button/Button.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"

#include <string>
#include <filesystem>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class ContentWindow : public EditorWindow
    {
    public:
        ContentWindow(Core::Editor* editor);

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

    private:
        std::filesystem::path current_path;

        Engine::Graphics::OpenGL::Texture::Texture2D* folder_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D* file_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D* left_arrow_texture;

        Engine::UI::ImGui::Renderer::TextRenderer text_renderer;

        Engine::UI::ImGui::Element::Button::Button back_button;

        void render_menu_bar();

        void content_single_click(const std::string& name);
        void content_double_click(const std::filesystem::path& path);
    };
}
