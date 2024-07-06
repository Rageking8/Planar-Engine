#include "Planar/Engine/UI/ImGui/Core/State/ModifiedState.hpp"

namespace Planar::Engine::UI::ImGui::Core::State
{
    ModifiedState::ModifiedState() : modified{}
    {

    }

    bool ModifiedState::get_modified(bool reset)
    {
        bool result = modified;

        if (reset)
        {
            clear_modified();
        }

        return result;
    }

    void ModifiedState::update_modified(bool value)
    {
        modified |= value;
    }

    void ModifiedState::clear_modified()
    {
        modified = false;
    }
}
