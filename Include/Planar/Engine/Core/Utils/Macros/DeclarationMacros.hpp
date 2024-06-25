#pragma once

#define PLANAR_FORWARD_DECLARE(ns, class_key, name) \
    namespace ns                                    \
    {                                               \
        class_key name;                             \
    }                                               \

#define PLANAR_FORWARD_DECLARE_CLASS(ns, name) \
    PLANAR_FORWARD_DECLARE(ns, class, name)    \

#define PLANAR_ENGINE_FORWARD_DECLARE_CLASS(ns, name)      \
    PLANAR_FORWARD_DECLARE_CLASS(Planar::Engine::ns, name) \
