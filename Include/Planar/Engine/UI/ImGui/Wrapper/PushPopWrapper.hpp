#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::UI::ImGui::Wrapper
{
    class PLANAR_API PushPopWrapper
    {
    public:
        PushPopWrapper();
        virtual ~PushPopWrapper();

        virtual void pop() = 0;

    protected:
        int push_count;
    };
}
