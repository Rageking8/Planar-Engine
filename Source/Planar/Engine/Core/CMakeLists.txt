target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    Application.cpp
    GLFWContext.cpp
    ImGuiContext.cpp
)

add_subdirectory(FileSystem)
add_subdirectory(Utils)
