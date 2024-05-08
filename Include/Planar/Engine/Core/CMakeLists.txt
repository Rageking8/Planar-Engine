target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    Application.hpp
    ExportMacros.hpp
    GLFWContext.hpp
    Links.hpp
    Version.hpp
)

add_subdirectory(FileSystem)
add_subdirectory(GUID)
add_subdirectory(Log)
add_subdirectory(Shell)
add_subdirectory(Utils)
