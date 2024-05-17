#pragma once

#include "Planar/Engine/UI/ImGui/Window/ImGuiWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiTextRenderer.hpp"
#include "Planar/Engine/Graphics/Texture/Texture.hpp"

namespace Planar::Editor::UI
{
    class ContentWindow :
        public Planar::Engine::UI::ImGui::Window::ImGuiWindow
    {
    public:
        ContentWindow();

        void render_window();

        void set_folder_texture(
            Planar::Engine::Graphics::Texture::Texture&
            new_folder_texture);
        void set_file_texture(
            Planar::Engine::Graphics::Texture::Texture&
            new_file_texture);

    private:
        Planar::Engine::Graphics::Texture::Texture* folder_texture;
        Planar::Engine::Graphics::Texture::Texture* file_texture;

        Planar::Engine::UI::ImGui::ImGuiTextRenderer text_renderer;
    };
}
