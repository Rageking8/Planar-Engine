target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    Application.cpp
    GLFWContext.cpp
)

add_subdirectory(FileSystem)
add_subdirectory(GUID)
add_subdirectory(Log)
add_subdirectory(Shell)
add_subdirectory(Utils)
