#pragma once

#include <stack>
#include <vector>
#include <memory>
#include <type_traits>

namespace Planar::Engine::Core::Utils::Stack
{
    template <typename T>
    T pop(std::stack<T>& stack);

    template <typename T>
    void push_raw_pointers_reverse(std::stack<T>& stack,
        const std::vector<std::shared_ptr<std::remove_pointer_t<T>>>&
        vector);
}

#include "Planar/Engine/Core/Utils/Stack/Stack.tpp"
