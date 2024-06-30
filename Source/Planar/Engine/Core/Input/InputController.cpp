#include "Planar/Engine/Core/Input/InputController.hpp"

#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Engine::Core::Input
{
    InputController::InputController()
    {

    }

    void InputController::add_key_event(int key, int scancode,
        int action, int mods)
    {
        if (action == GLFW_PRESS || action == GLFW_RELEASE)
        {
            key_map[key].set_action(action);
        }
    }

    bool InputController::key_down(int key)
    {
        return key_map[key].get_action() == GLFW_PRESS;
    }
}
