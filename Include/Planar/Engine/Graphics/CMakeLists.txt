target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    Color.hpp
    SupportedGraphicsAPI.hpp
)

add_subdirectory(Image)
add_subdirectory(Load)
add_subdirectory(Texture)
