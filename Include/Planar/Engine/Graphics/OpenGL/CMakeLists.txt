target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    Vector3.hpp
)

add_subdirectory(Buffer)
add_subdirectory(Core)
add_subdirectory(Create)
add_subdirectory(Load)
add_subdirectory(Shader)
add_subdirectory(Texture)
