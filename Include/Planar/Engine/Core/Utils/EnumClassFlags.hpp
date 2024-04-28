#pragma once

#include "Planar/Engine/Core/Utils/Concepts/EnumClass.hpp"

#include <type_traits>

#define PLANAR_BEGIN_ENUM_CLASS_FLAG(ns, name)                            \
    namespace ns                                                          \
    {                                                                     \
        enum class name : unsigned;                                       \
    }                                                                     \
                                                                          \
    template <>                                                           \
    inline constexpr bool                                                 \
        Planar::Engine::Core::Utils::is_enum_class_flag<ns::name> = true; \
                                                                          \
    namespace ns                                                          \
    {                                                                     \
        enum class name : unsigned

#define PLANAR_END_ENUM_CLASS_FLAG }

namespace Planar::Engine::Core::Utils
{
    template <Concepts::UnsignedEnumClass T>
    inline constexpr bool is_enum_class_flag = false;

    template <typename T>
    concept EnumClassFlag = is_enum_class_flag<T>;

    template <Concepts::EnumClass T>
    constexpr std::underlying_type_t<T> to_underlying(T e);

    template <EnumClassFlag T>
    constexpr T operator|(T lhs, T rhs);

    template <EnumClassFlag T>
    constexpr bool has(T value, T test);
}

#include "Planar/Engine/Core/Utils/EnumClassFlags.tpp"
