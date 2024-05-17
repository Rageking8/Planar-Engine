#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class SceneWindow : public EditorWindow
    {
    public:
        SceneWindow();

        virtual void render_window() override;
    };
}
