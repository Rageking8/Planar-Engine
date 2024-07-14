#pragma once

#include "Planar/Editor/UI/Window/Core/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class SceneWindow : public Core::EditorWindow
    {
    public:
        SceneWindow(Editor::Core::Editor* editor);

        virtual void render_window() override;
    };
}
