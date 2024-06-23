target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Application.hpp
    GameObject.hpp
    GLFWContext.hpp
)

add_subdirectory(Archive)
add_subdirectory(Constants)
add_subdirectory(Execute)
add_subdirectory(FileSystem)
add_subdirectory(GUID)
add_subdirectory(Log)
add_subdirectory(Shell)
add_subdirectory(Utils)
