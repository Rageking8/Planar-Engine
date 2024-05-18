target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    SupportedGraphicsAPI.cpp
)

add_subdirectory(Create)
add_subdirectory(Image)
add_subdirectory(Load)
add_subdirectory(Texture)
