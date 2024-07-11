namespace Planar::Engine::Math
{
    template <Core::Utils::Concepts::Arithmetic T>
    inline Pos2D<T>::Pos2D() : x{}, y{}
    {

    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline Pos2D<T>::Pos2D(T value) :
        x{ value }, y{ value }
    {

    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline Pos2D<T>::Pos2D(T x, T y) :
        x{ x }, y{ y }
    {

    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline Pos2D<T>::Pos2D(std::array<T, 2> array) :
        x{ array[0] }, y{ array[1] }
    {

    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline Pos2D<T> Pos2D<T>::operator-(T value) const
    {
        Pos2D<T> result = *this;
        result.x -= value;
        result.y -= value;

        return result;
    }

    template <Core::Utils::Concepts::Arithmetic T>
    inline std::array<T, 2> Pos2D<T>::get_array() const
    {
        return { x, y };
    }
}
