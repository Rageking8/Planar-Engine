#pragma once

#include "Planar/Editor/UI/Element/Component.hpp"
#include "Planar/Engine/Component/CameraController2D.hpp"

namespace Planar::Editor::UI::Element
{
    class CameraController2D :
        public Component<Engine::Component::CameraController2D>
    {
    public:
        CameraController2D();

        virtual bool get_modified(bool reset = true) override;

    private:
        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* camera) override;
        virtual void write_values_impl(ComponentType* camera) override;
    };
}
