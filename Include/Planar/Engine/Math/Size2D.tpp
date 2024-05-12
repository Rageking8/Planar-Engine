namespace Planar::Engine::Math
{
    template <Planar::Engine::Core::Utils::Concepts::Arithmetic T>
    Size2D<T>::Size2D() : width{}, height{}
    {

    }

    template <Planar::Engine::Core::Utils::Concepts::Arithmetic T>
    Size2D<T>::Size2D(T size) :
        width{ size }, height{ size }
    {

    }

    template <Planar::Engine::Core::Utils::Concepts::Arithmetic T>
    Size2D<T>::Size2D(T width, T height) :
        width{ width }, height{ height }
    {

    }
}
