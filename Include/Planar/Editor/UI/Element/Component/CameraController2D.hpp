#pragma once

#include "Planar/Editor/UI/Element/Component/Component.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Component/CameraController2D.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/DragFloat.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class CameraController2D :
        public Component<Engine::Component::CameraController2D>
    {
    public:
        CameraController2D();

        virtual bool get_modified(bool reset = true) override;

        Engine::Math::Size2Df get_horizontal_speed() const;
        void set_horizontal_speed(Engine::Math::Size2Df
            new_horizontal_speed);

        Engine::Math::Size2Df get_vertical_speed() const;
        void set_vertical_speed(Engine::Math::Size2Df
            new_vertical_speed);

    private:
        Engine::UI::ImGui::Element::Drag::DragFloat2 horizontal_speed;
        Engine::UI::ImGui::Element::Drag::DragFloat2 vertical_speed;

        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* camera_controller)
            override;
        virtual void write_values_impl(ComponentType* camera_controller)
            override;
    };
}
