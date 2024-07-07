#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class Camera2D :
        public Core::Component<Engine::Component::Camera2D>
    {
    public:
        Camera2D();

        virtual bool get_modified(bool reset = true) override;

    private:
        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* camera) override;
        virtual void write_values_impl(ComponentType* camera) override;
    };
}
