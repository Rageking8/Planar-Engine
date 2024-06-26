#pragma once

#include "Planar/Editor/UI/Element/Component.hpp"
#include "Planar/Engine/UI/ImGui/Element/DragFloat.hpp"

namespace Planar::Editor::UI::Element
{
    class Transform2D : public Component
    {
    public:
        Transform2D();

    private:
        Engine::UI::ImGui::Element::DragFloat2 position;
        Engine::UI::ImGui::Element::DragFloat1 rotation;

        virtual void render_content() override;
    };
}
