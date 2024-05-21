target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    Vector3.hpp
    VertexArrayObject.hpp
    VertexArrayObject.tpp
)

add_subdirectory(Buffer)
add_subdirectory(Create)
add_subdirectory(Shader)
