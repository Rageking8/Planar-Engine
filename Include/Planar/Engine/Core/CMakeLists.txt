target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Application.hpp
    ApplicationAsset.hpp
)

add_subdirectory(Constants)
add_subdirectory(FileSystem)
add_subdirectory(GLFW)
add_subdirectory(GUID)
add_subdirectory(Input)
add_subdirectory(Log)
add_subdirectory(Mixin)
add_subdirectory(Shell)
add_subdirectory(Sprite)
add_subdirectory(Utils)
