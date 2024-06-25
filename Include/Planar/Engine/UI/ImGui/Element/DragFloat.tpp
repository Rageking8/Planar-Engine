#include "Planar/Engine/UI/ImGui/Element/DragFloat.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Engine::UI::ImGui::Element
{
    template <std::size_t N>
    inline DragFloat<N>::DragFloat(const std::string& text,
        const std::string& id) : text{ text }, id{ id }, value{}
    {

    }

    template <>
    inline void DragFloat<1>::render()
    {
        drag_float(get_label(), value.front());
    }

    template <>
    inline void DragFloat<2>::render()
    {
        drag_float_2(get_label(), value);
    }

    template <std::size_t N>
    inline DragFloat<N>::ValueT DragFloat<N>::get_value() const
    {
        return value;
    }

    template <std::size_t N>
    inline float DragFloat<N>::get_x() const
    {
        static_assert(N >= 1, "Getting X is not allowed");

        return value[0];
    }

    template <std::size_t N>
    inline float DragFloat<N>::get_y() const
    {
        static_assert(N >= 2, "Getting Y is not allowed");

        return value[1];
    }

    template <std::size_t N>
    inline void DragFloat<N>::set_text(const std::string& new_text)
    {
        text = new_text;
    }

    template <std::size_t N>
    inline void DragFloat<N>::set_id(const std::string& new_id)
    {
        id = new_id;
    }

    template <std::size_t N>
    inline void DragFloat<N>::set_value(ValueT new_value)
    {
        value = new_value;
    }

    template <std::size_t N>
    inline void DragFloat<N>::set_x(float new_x)
    {
        static_assert(N >= 1, "Setting X is not allowed");

        value[0] = new_x;
    }

    template <std::size_t N>
    inline void DragFloat<N>::set_y(float new_y)
    {
        static_assert(N >= 2, "Setting Y is not allowed");

        value[1] = new_y;
    }

    template <std::size_t N>
    inline std::string DragFloat<N>::get_label() const
    {
        return "##" + text + id;
    }
}
