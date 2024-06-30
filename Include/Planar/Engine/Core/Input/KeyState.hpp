#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::Core::Input
{
    class PLANAR_API KeyState
    {
    public:
        KeyState();

        int get_action() const;
        void set_action(int new_action);

    private:
        int action;
    };
}
