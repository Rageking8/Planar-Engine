#include "Planar/Engine/Core/Input/KeyState.hpp"

#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Engine::Core::Input
{
    KeyState::KeyState() : action{ GLFW_RELEASE }
    {

    }

    int KeyState::get_action() const
    {
        return action;
    }

    void KeyState::set_action(int new_action)
    {
        action = new_action;
    }
}
