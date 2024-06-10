#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Graphics/Color.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API ProgressBar : public Element
    {
    public:
        ProgressBar(unsigned value = 0, unsigned max = 0,
            Math::Size2Df size = { 100.f, 12.f },
            Graphics::Color foreground_color = { 0.f, 1.f, 0.f, 1.f },
            Graphics::Color background_color = { 0.f, 0.f, 0.f, 0.f });

        virtual void render() override;

        unsigned get_value() const;
        unsigned get_max() const;
        Math::Size2Df get_size() const;
        float get_width() const;
        float get_height() const;
        Graphics::Color get_foreground_color() const;
        Graphics::Color get_background_color() const;

        void increment(unsigned delta = 1);
        void set_value(unsigned new_value);
        void set_max(unsigned new_max);
        void set_size(Math::Size2Df new_size);
        void set_width(float new_width);
        void set_height(float new_height);
        void set_foreground_color(
            Graphics::Color new_foreground_color);
        void set_background_color(
            Graphics::Color new_background_color);

    private:
        unsigned value;
        unsigned max;
        Math::Size2Df size;
        Graphics::Color foreground_color;
        Graphics::Color background_color;
    };
}
