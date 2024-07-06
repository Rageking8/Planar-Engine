target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    CameraController2D.hpp
    Camera2D.hpp
    Component.hpp
    Component.tpp
    ComponentBase.hpp
    ComponentFunction.hpp
    ComponentFunction.tpp
    ComponentMacros.hpp
    ComponentType.hpp
    Transform2D.hpp
)

add_subdirectory(Mixin)
