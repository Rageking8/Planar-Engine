#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/Drag.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class Transform2D :
        public Core::Component<Engine::Component::Transform2D>
    {
    public:
        Transform2D();

        virtual bool get_modified(bool reset = true) override;

    private:
        Engine::UI::ImGui::Element::Drag::DragFloat2 position;
        Engine::UI::ImGui::Element::Drag::DragFloat1 rotation;
        Engine::UI::ImGui::Element::Drag::DragFloat2 scale;

        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* transform) override;
        virtual void write_values_impl(ComponentType* transform) override;
    };
}
