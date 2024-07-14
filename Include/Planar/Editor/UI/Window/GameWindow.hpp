#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/UI/ImGui/Renderer/TextRenderer.hpp"
#include "Planar/Engine/Graphics/OpenGL/Framebuffer/Framebuffer.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class GameWindow : public EditorWindow
    {
    public:
        GameWindow(Core::Editor* editor);

        virtual void init() override;
        virtual void update() override;

        virtual void render_window() override;

    private:
        Engine::Math::Size2Df content_size;

        Engine::Graphics::OpenGL::Framebuffer::Framebuffer framebuffer;

        Engine::UI::ImGui::Renderer::TextRenderer text_renderer;

        void render_game();
    };
}
