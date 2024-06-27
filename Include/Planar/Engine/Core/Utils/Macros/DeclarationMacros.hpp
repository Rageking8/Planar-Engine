#pragma once

#define PLANAR_FORWARD_DECLARE(ns, key, name) \
    namespace ns                              \
    {                                         \
        key name;                             \
    }                                         \

#define PLANAR_FORWARD_DECLARE_CLASS(ns, name) \
    PLANAR_FORWARD_DECLARE(ns, class, name)    \

#define PLANAR_FORWARD_DECLARE_ENUM_CLASS(ns, name) \
    PLANAR_FORWARD_DECLARE(ns, enum class, name)    \

#define PLANAR_ENGINE_FORWARD_DECLARE_CLASS(ns, name)      \
    PLANAR_FORWARD_DECLARE_CLASS(Planar::Engine::ns, name) \
