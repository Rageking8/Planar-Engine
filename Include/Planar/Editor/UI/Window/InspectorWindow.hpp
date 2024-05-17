#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class InspectorWindow : public EditorWindow
    {
    public:
        InspectorWindow();

        virtual void render_window() override;
    };
}
