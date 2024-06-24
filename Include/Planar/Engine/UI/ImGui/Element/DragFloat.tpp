#include "Planar/Engine/UI/ImGui/Element/DragFloat.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Engine::UI::ImGui::Element
{
    template <std::size_t N>
    inline DragFloat<N>::DragFloat(const std::string& label) :
        label{ label }, value{}
    {

    }

    template <>
    inline void DragFloat<1>::render()
    {
        drag_float(label, value.front());
    }

    template <>
    inline void DragFloat<2>::render()
    {
        drag_float_2(label, value);
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
    inline void DragFloat<N>::set_label(const std::string& new_label)
    {
        label = new_label;
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
}
