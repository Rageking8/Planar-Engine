#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Component/CameraController2D.hpp"
#include "Planar/Engine/UI/ImGui/Element/DropDown.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/Drag.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class CameraController2D :
        public Core::Component<Engine::Component::CameraController2D>
    {
    public:
        CameraController2D();

        virtual bool get_modified(bool reset = true) override;

        PLANAR_DECLARE_GET_SET(Engine::Math::Size2Df, horizontal_speed)
        PLANAR_DECLARE_GET_SET(Engine::Math::Size2Df, vertical_speed)

    private:
        Engine::UI::ImGui::Element::DropDown mode_drop_down;
        Engine::UI::ImGui::Element::Drag::DragFloat2 horizontal_speed;
        Engine::UI::ImGui::Element::Drag::DragFloat2 vertical_speed;

        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* camera_controller)
            override;
        virtual void write_values_impl(ComponentType* camera_controller)
            override;
    };
}
