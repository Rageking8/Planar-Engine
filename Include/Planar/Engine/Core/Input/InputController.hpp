#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Input/KeyState.hpp"

#include <unordered_map>

namespace Planar::Engine::Core::Input
{
    class PLANAR_API InputController
    {
    public:
        InputController();

        void add_key_event(int key, int scancode, int action,
            int mods);

        bool key_down(int key);

    private:
        std::unordered_map<int, KeyState> key_map;
    };
}
