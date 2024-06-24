#pragma once

#include "Planar/Engine/UI/ImGui/Element/Element.hpp"

#include <array>
#include <string>
#include <cstddef>

namespace Planar::Engine::UI::ImGui::Element
{
    template <std::size_t N = 1>
    class DragFloat : public Element
    {
        static_assert(N > 0, "`N` must be greater than `0`");

    public:
        using ValueT = std::array<float, N>;

        DragFloat(const std::string& label = "");

        virtual void render() override;

        ValueT get_value() const;
        float get_x() const;
        float get_y() const;

        void set_label(const std::string& new_label);
        void set_value(ValueT new_value);
        void set_x(float new_x);
        void set_y(float new_y);

    private:
        std::string label;
        ValueT value;
    };

    using DragFloat1 = DragFloat<1>;
    using DragFloat2 = DragFloat<2>;
}

#include "Planar/Engine/UI/ImGui/Element/DragFloat.tpp"
