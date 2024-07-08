target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    ObjectHandlingMode.hpp
    ObjectManager.hpp
    Resource.hpp
    VertexArrayObject.hpp
    VertexArrayObject.tpp
    ViewportScope.hpp
)

add_subdirectory(Vertex)
