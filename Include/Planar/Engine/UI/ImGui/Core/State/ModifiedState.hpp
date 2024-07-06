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

        void clear_modified();

    private:
        bool modified;
    };
}
