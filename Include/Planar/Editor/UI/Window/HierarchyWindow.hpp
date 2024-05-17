#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class HierarchyWindow : public EditorWindow
    {
    public:
        HierarchyWindow();

        virtual void render_window() override;
    };
}
