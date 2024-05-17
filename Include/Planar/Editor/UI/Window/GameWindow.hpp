#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class GameWindow : public EditorWindow
    {
    public:
        GameWindow();

        virtual void render_window() override;
    };
}
