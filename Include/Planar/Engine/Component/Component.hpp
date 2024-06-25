#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::Component
{
    class PLANAR_API Component
    {
    public:
        Component();

        bool get_active() const;
        void set_active(bool new_active);

    private:
        bool active;
    };
}
