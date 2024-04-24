#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"

namespace Planar::Engine::Core
{
    class PLANAR_API GLFWContext
    {
    public:
        GLFWContext();
        ~GLFWContext();

        bool init();
        void terminate();

    private:
        bool has_init;
    };
}
