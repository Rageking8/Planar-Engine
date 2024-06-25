#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(Planar::Editor::Core, Editor)

namespace Planar::Editor::UI::Window
{
    class SceneWindow : public EditorWindow
    {
    public:
        SceneWindow(Core::Editor* editor);

        virtual void render_window() override;
    };
}
