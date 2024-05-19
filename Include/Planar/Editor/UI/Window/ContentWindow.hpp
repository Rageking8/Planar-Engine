#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Renderer/ImGuiTextRenderer.hpp"
#include "Planar/Engine/Graphics/Texture/Texture.hpp"

namespace Planar::Editor::UI::Window
{
    class ContentWindow : public EditorWindow
    {
    public:
        ContentWindow();

        virtual void render_window() override;

        void set_folder_texture(
            Planar::Engine::Graphics::Texture::Texture&
            new_folder_texture);
        void set_file_texture(
            Planar::Engine::Graphics::Texture::Texture&
            new_file_texture);

    private:
        Planar::Engine::Graphics::Texture::Texture* folder_texture;
        Planar::Engine::Graphics::Texture::Texture* file_texture;

        Planar::Engine::UI::ImGui::Renderer::ImGuiTextRenderer
            text_renderer;
    };
}
