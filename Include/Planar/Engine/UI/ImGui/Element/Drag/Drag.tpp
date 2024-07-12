#include "Planar/Engine/UI/ImGui/Element/Drag/Drag.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/DragFunction.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Engine::UI::ImGui::Element::Drag
{
    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline Drag<T, N>::Drag(const std::string& text,
        Core::Size::Width drag_width, float drag_x_pos,
        bool generate_unique_id) : text{ text }, value{},
        drag_width{ drag_width }, drag_x_pos{ drag_x_pos }
    {
        if (generate_unique_id)
        {
            id = generate_unique_label();
        }
    }

    template <>
    inline void Drag<int, 1>::render()
    {
        render_text();
        drag_width.set();
        update_modified(drag_int(get_label(), value.front()));
    }

    template <>
    inline void Drag<int, 2>::render()
    {
        render_text();
        drag_width.set();
        update_modified(drag_int_2(get_label(), value));
    }

    template <>
    inline void Drag<float, 1>::render()
    {
        render_text();
        drag_width.set();
        update_modified(drag_float(get_label(), value.front()));
    }

    template <>
    inline void Drag<float, 2>::render()
    {
        render_text();
        drag_width.set();
        update_modified(drag_float_2(get_label(), value));
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline Drag<T, N>::ValueT Drag<T, N>::get_value() const
    {
        return value;
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline T Drag<T, N>::get_x() const
    {
        static_assert(N >= 1, "Getting X is not allowed");

        return value[0];
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline T Drag<T, N>::get_y() const
    {
        static_assert(N >= 2, "Getting Y is not allowed");

        return value[1];
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline void Drag<T, N>::set_text(const std::string& new_text)
    {
        text = new_text;
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline void Drag<T, N>::set_id(const std::string& new_id)
    {
        id = new_id;
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline void Drag<T, N>::set_value(ValueT new_value)
    {
        value = new_value;
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline void Drag<T, N>::set_x(T new_x)
    {
        static_assert(N >= 1, "Setting X is not allowed");

        value[0] = new_x;
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline void Drag<T, N>::set_y(T new_y)
    {
        static_assert(N >= 2, "Setting Y is not allowed");

        value[1] = new_y;
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline std::string Drag<T, N>::get_label() const
    {
        return "##" + text + id;
    }

    template <Engine::Core::Utils::Concepts::Arithmetic T,
        std::size_t N>
    inline void Drag<T, N>::render_text() const
    {
        if (text.empty())
        {
            return;
        }

        ImGui::text(text, true);
        same_line();
        Core::Cursor::set_x(drag_x_pos);
    }
}
