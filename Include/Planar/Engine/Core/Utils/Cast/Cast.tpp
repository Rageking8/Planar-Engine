#include "Planar/Engine/Core/Utils/Cast/Cast.hpp"

namespace Planar::Engine::Core::Utils::Cast
{
    template <typename Derived, Concepts::Polymorphic Base>
        requires std::derived_from<Derived, Base> &&
        (!std::same_as<Derived, Base>)
    Derived* unique_ptr_downcast(std::unique_ptr<Base>& pointer)
    {
        return static_cast<Derived*>(pointer.get());
    }
}
