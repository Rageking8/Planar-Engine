#include "Planar/Editor/Core/Input/InputHandler.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/Core/Input/InputController.hpp"

#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Editor::Core::Input
{
    InputHandler::InputHandler(Editor* editor) :
        editor{ editor }, save_shortcut_ready{}
    {

    }

    void InputHandler::update()
    {
        Engine::Core::Input::InputController& input =
            editor->get_input_controller();

        const bool key_s_down = input.key_down('S');
        if (save_shortcut_ready && key_s_down)
        {
            editor->save_all();
        }

        save_shortcut_ready = !key_s_down &&
            input.key_down(GLFW_KEY_LEFT_CONTROL);
    }
}