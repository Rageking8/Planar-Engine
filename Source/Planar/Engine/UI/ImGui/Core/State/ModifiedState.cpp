#include "Planar/Engine/UI/ImGui/Core/State/ModifiedState.hpp"

namespace Planar::Engine::UI::ImGui::Core::State
{
    ModifiedState::ModifiedState() : modified{}
    {

    }

    bool ModifiedState::get_modified(bool reset)
    {
        bool result = modified;

        modified = reset ? false : modified;

        return result;
    }

    void ModifiedState::update_modified(bool value)
    {
        modified |= value;
    }
}
