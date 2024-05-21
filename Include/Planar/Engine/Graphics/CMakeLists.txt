target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    Color.hpp
    SupportedGraphicsAPI.hpp
)

add_subdirectory(Create)
add_subdirectory(Image)
add_subdirectory(Load)
add_subdirectory(OpenGL)
add_subdirectory(Texture)
