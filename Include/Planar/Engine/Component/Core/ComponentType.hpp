#pragma once

#define PLANAR_ALL_COMPONENT(macro) \
    macro(Transform2D)              \
    macro(Camera2D)                 \
    macro(CameraController2D)       \
    macro(SpriteRenderer)           \
    macro(CharacterController2D)    \

namespace Planar::Engine::Component::Core
{
    enum class ComponentType
    {
        ComponentBase,

        #define PLANAR_ENUM_CLASS_ENTRY(entry) entry,
        PLANAR_ALL_COMPONENT(PLANAR_ENUM_CLASS_ENTRY)
        #undef PLANAR_ENUM_CLASS_ENTRY
    };
}
