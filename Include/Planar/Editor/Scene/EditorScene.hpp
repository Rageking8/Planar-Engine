#pragma once

#include "Planar/Editor/Scene/Scene.hpp"
#include "Planar/Editor/UI/Menu/EditorMenuBar.hpp"
#include "Planar/Editor/UI/Window/Core/EditorWindowManager.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::Scene
{
    class EditorScene : public Scene
    {
    public:
        EditorScene(Core::Editor* editor);

        virtual void init() override;
        virtual void update() override;
        virtual void render() override;

    private:
        UI::Window::Core::EditorWindowManager window_manager;
        UI::Menu::EditorMenuBar menu_bar;

        Engine::Graphics::OpenGL::Texture::Texture2D file_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D folder_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D left_arrow_texture;

        void restore_default_layout() const;

        void load_icons();
    };
}
