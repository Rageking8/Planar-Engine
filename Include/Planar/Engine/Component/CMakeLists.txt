target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    CameraController2D.hpp
    Camera2D.hpp
    Transform2D.hpp
)

add_subdirectory(Core)
add_subdirectory(Mixin)
