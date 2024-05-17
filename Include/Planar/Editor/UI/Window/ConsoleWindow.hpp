#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class ConsoleWindow : public EditorWindow
    {
    public:
        ConsoleWindow();

        virtual void render_window() override;
    };
}
