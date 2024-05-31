#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API IntSlider : public Element
    {
    public:
        IntSlider(int value, int min_value, int max_value,
            const std::string& label = "", float width = 0.f);

        virtual void render() override;

        int get_value() const;

        void set_render_label(bool new_render_label);
        void set_min_value(int new_min_value);
        void set_max_value(int new_max_value);
        void set_width(float new_width);

    private:
        std::string label;
        bool render_label;
        int value;
        int min_value;
        int max_value;
        float width;
    };
}
