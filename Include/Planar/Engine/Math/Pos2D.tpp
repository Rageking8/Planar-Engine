namespace Planar::Engine::Math
{
    template <Planar::Engine::Core::Utils::Concepts::Arithmetic T>
    inline Pos2D<T>::Pos2D() : x{}, y{}
    {

    }

    template <Planar::Engine::Core::Utils::Concepts::Arithmetic T>
    inline Pos2D<T>::Pos2D(T value) :
        x{ value }, y{ value }
    {

    }

    template <Planar::Engine::Core::Utils::Concepts::Arithmetic T>
    inline Pos2D<T>::Pos2D(T x, T y) :
        x{ x }, y{ y }
    {

    }
}
