target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Application.cpp
    GLFWContext.cpp
)

add_subdirectory(Archive)
add_subdirectory(Execute)
add_subdirectory(FileSystem)
add_subdirectory(GUID)
add_subdirectory(Input)
add_subdirectory(Log)
add_subdirectory(Shell)
add_subdirectory(Utils)
