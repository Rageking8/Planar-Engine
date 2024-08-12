target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    AudioSourceAsset.hpp
    CameraController2DAsset.hpp
    Camera2DAsset.hpp
    CharacterController2DAsset.hpp
    ScriptAsset.hpp
    SpriteRendererAsset.hpp
    Transform2DAsset.hpp
)

add_subdirectory(Core)
add_subdirectory(Mixin)
