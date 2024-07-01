#pragma once

#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/State/ModifiedState.hpp"

#include <array>
#include <string>
#include <cstddef>

namespace Planar::Engine::UI::ImGui::Element::Drag
{
    template <std::size_t N = 1>
    class DragFloat : public Element,
        private Core::State::ModifiedState
    {
        static_assert(N > 0, "`N` must be greater than `0`");

    public:
        using ValueT = std::array<float, N>;

        DragFloat(const std::string& text = "",
            const std::string& id = "",
            Core::Size::Width drag_width = {},
            float drag_x_pos = 0.f);

        using ModifiedState::get_modified;

        virtual void render() override;

        ValueT get_value() const;
        float get_x() const;
        float get_y() const;

        void set_text(const std::string& new_text);
        void set_id(const std::string& new_id);
        void set_value(ValueT new_value);
        void set_x(float new_x);
        void set_y(float new_y);

    private:
        std::string text;
        std::string id;
        ValueT value;
        Core::Size::Width drag_width;
        float drag_x_pos;

        std::string get_label() const;

        void render_text() const;
    };

    using DragFloat1 = DragFloat<1>;
    using DragFloat2 = DragFloat<2>;
}

#include "Planar/Engine/UI/ImGui/Element/Drag/DragFloat.tpp"
