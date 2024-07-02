#pragma once

#include "Planar/Editor/UI/Element/Component.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/DragFloat.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Component)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Transform2D)

namespace Planar::Editor::UI::Element
{
    class Transform2D : public Component
    {
    public:
        Transform2D();

        virtual bool get_modified(bool reset = true) override;

        virtual void set(
            std::shared_ptr<Engine::Component::Component> component) override;
        virtual bool write(
            std::shared_ptr<Engine::Component::Component> component,
            bool force = false) override;

        Engine::Math::Pos2Df get_position() const;
        void set_position(Engine::Math::Pos2Df new_position);

        float get_rotation() const;
        void set_rotation(float new_rotation);

    private:
        Engine::UI::ImGui::Element::Drag::DragFloat2 position;
        Engine::UI::ImGui::Element::Drag::DragFloat1 rotation;

        virtual void render_content() override;
    };
}
