target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Color.hpp
    SupportedGraphicsAPI.hpp
)

add_subdirectory(Image)
add_subdirectory(OpenGL)
