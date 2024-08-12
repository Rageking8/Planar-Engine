target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    AudioSource.hpp
    CameraController2D.hpp
    Camera2D.hpp
    CharacterController2D.hpp
    Script.hpp
    SpriteRenderer.hpp
    Transform2D.hpp
)

add_subdirectory(Core)
add_subdirectory(Mixin)
