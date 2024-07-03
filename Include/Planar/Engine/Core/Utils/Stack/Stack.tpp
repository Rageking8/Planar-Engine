#include "Planar/Engine/Core/Utils/Stack/Stack.hpp"

#include <cstddef>

namespace Planar::Engine::Core::Utils::Stack
{
    template <typename T>
    T pop(std::stack<T>& stack)
    {
        T top = std::move(stack.top());
        stack.pop();

        return top;
    }

    template <typename T>
    void push_raw_pointers_reverse(std::stack<T>& stack,
        const std::vector<std::shared_ptr<std::remove_pointer_t<T>>>&
        vector)
    {
        for (std::size_t i = vector.size(); i-- > 0;)
        {
            stack.push(vector[i].get());
        }
    }
}
