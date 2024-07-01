#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::UI::ImGui::Core::State
{
    class PLANAR_API ModifiedState
    {
    public:
        ModifiedState();

        bool get_modified(bool reset = true);

        void update_modified(bool value);

    private:
        bool modified;
    };
}
