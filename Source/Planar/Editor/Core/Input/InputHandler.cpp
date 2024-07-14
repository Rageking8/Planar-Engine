#include "Planar/Editor/Core/Input/InputHandler.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Scene/EditorScene.hpp"
#include "Planar/Engine/Core/Input/InputController.hpp"

#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Editor::Core::Input
{
    InputHandler::InputHandler(Editor* editor) :
        editor{ editor }, save_shortcut_ready{},
        open_build_window_shortcut_ready{}
    {

    }

    void InputHandler::update()
    {
        handle_ctrl_shortcut('S', save_shortcut_ready, [=]
            {
                editor->save_all();
            });

        handle_ctrl_shortcut('B', open_build_window_shortcut_ready, [=]
            {
                editor->get_editor_scene()->open_build_window();
            });
    }

    void InputHandler::handle_ctrl_shortcut(int key, bool& ready,
        const std::function<void()>& callback)
    {
        Engine::Core::Input::InputController& input =
            editor->get_input_controller();

        const bool key_down = input.key_down(key);
        if (ready && key_down)
        {
            callback();
        }

        ready = !key_down && input.key_down(GLFW_KEY_LEFT_CONTROL);
    }
}
