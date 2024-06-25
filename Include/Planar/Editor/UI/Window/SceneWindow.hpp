#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class SceneWindow : public EditorWindow
    {
    public:
        SceneWindow(Core::Editor* editor);

        virtual void render_window() override;
    };
}
