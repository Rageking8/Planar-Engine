target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    CameraController2DAsset.hpp
    Camera2DAsset.hpp
    SpriteRendererAsset.hpp
    Transform2DAsset.hpp
)

add_subdirectory(Core)
add_subdirectory(Mixin)
