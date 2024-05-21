#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Wrapper/PushPopWrapper.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

namespace Planar::Engine::UI::ImGui::Style
{
    class PLANAR_API StyleVar : public Wrapper::PushPopWrapper
    {
    public:
        ~StyleVar();

        void set_frame_padding(Planar::Engine::Math::Size2Df padding);

        virtual void pop() override;
    };
}
