#pragma once

#include "Planar/Editor/UI/Element/Component.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Component)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Camera2D)

namespace Planar::Editor::UI::Element
{
    class Camera2D : public Component
    {
    public:
        Camera2D();

        virtual bool get_modified(bool reset = true) override;

        virtual void set(
            std::shared_ptr<Engine::Component::Component> component)
            override;
        virtual bool write(
            std::shared_ptr<Engine::Component::Component> component,
            bool force = false) override;

    private:
        virtual void render_content() override;
    };
}
