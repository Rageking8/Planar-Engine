#pragma once

#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class SceneWindow : public EditorWindow
    {
    public:
        SceneWindow(Core::Editor* editor);

        virtual void render_window() override;
    };
}
