#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(Editor::Core, Editor)

namespace Planar::Editor::UI::Window
{
    class ConsoleWindow : public EditorWindow
    {
    public:
        ConsoleWindow(Core::Editor* editor);

        virtual void render_window() override;
    };
}
