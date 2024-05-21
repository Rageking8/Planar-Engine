target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    VertexArrayObject.cpp
)

add_subdirectory(Create)
add_subdirectory(Load)
add_subdirectory(Shader)
