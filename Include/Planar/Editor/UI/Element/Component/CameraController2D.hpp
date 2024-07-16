#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Editor/UI/Element/AssetReference.hpp"
#include "Planar/Engine/Component/CameraController2D.hpp"
#include "Planar/Engine/UI/ImGui/Element/DropDown.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/Drag.hpp"

#include <string>

namespace Planar::Editor::UI::Element::Component
{
    class CameraController2D :
        public Core::Component<Engine::Component::CameraController2D>
    {
    public:
        CameraController2D();

        virtual bool get_modified(bool reset = true) override;

    private:
        Engine::UI::ImGui::Element::DropDown mode_drop_down;
        Engine::UI::ImGui::Element::Drag::DragFloat2 horizontal_speed;
        Engine::UI::ImGui::Element::Drag::DragFloat2 vertical_speed;
        AssetReference tracked_transform;
        Engine::UI::ImGui::Element::Drag::DragFloat1 horizontal_lerp;
        Engine::UI::ImGui::Element::Drag::DragFloat1 vertical_lerp;

        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* camera_controller)
            override;
        virtual void write_values_impl(ComponentType* camera_controller)
            override;

        std::string map_tracked_transform(std::string asset);
        void update_tracked_transform_text(
            std::string new_tracked_transform);
    };
}
