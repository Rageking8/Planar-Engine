#pragma once

#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <functional>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::Core::Input
{
    class InputHandler
    {
    public:
        InputHandler(Editor* editor);

        void update();

    private:
        Editor* editor;

        bool save_shortcut_ready;
        bool open_build_window_shortcut_ready;

        void handle_ctrl_shortcut(int key, bool& ready,
            const std::function<void()>& callback);
    };
}
