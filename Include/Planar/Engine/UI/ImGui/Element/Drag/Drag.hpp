#pragma once

#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/State/ModifiedState.hpp"
#include "Planar/Engine/Core/Utils/Concepts/Arithmetic.hpp"

#include <array>
#include <string>
#include <cstddef>

namespace Planar::Engine::UI::ImGui::Element::Drag
{
    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N = 1>
    class Drag : public Element,
        private Core::State::ModifiedState
    {
        static_assert(N > 0, "`N` must be greater than `0`");

    public:
        using ValueT = std::array<T, N>;

        Drag(const std::string& text = "",
            Core::Size::Width drag_width = {},
            float drag_x_pos = 0.f, bool generate_unique_id = false);

        using ModifiedState::get_modified;

        virtual void render() override;

        ValueT get_value() const;
        T get_x() const;
        T get_y() const;

        void set_text(const std::string& new_text);
        void set_id(const std::string& new_id);
        void set_value(ValueT new_value);
        void set_x(T new_x);
        void set_y(T new_y);

    private:
        std::string text;
        std::string id;
        ValueT value;
        Core::Size::Width drag_width;
        float drag_x_pos;

        std::string get_label() const;

        void render_text() const;
    };

    using DragInt1 = Drag<int, 1>;
    using DragInt2 = Drag<int, 2>;

    using DragFloat1 = Drag<float, 1>;
    using DragFloat2 = Drag<float, 2>;
}

#include "Planar/Engine/UI/ImGui/Element/Drag/Drag.tpp"
