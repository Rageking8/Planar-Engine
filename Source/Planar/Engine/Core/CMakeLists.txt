target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Application.cpp
    ApplicationAsset.cpp
)

add_subdirectory(FileSystem)
add_subdirectory(GLFW)
add_subdirectory(GUID)
add_subdirectory(Input)
add_subdirectory(Log)
add_subdirectory(Shell)
add_subdirectory(Sprite)
add_subdirectory(Utils)
