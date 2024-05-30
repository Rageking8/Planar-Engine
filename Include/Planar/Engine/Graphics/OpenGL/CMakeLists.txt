target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Vector3.hpp
)

add_subdirectory(Buffer)
add_subdirectory(Core)
add_subdirectory(Framebuffer)
add_subdirectory(Function)
add_subdirectory(Render)
add_subdirectory(Shader)
add_subdirectory(Texture)
