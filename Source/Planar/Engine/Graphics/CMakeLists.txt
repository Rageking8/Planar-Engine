target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    SupportedGraphicsAPI.cpp
)

add_subdirectory(Image)
add_subdirectory(OpenGL)
