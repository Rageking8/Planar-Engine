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
    inline Pos2D<T>& Pos2D<T>::operator-(T value)
    {
        x -= value;
        y -= value;

        return *this;
    }
}
