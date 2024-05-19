target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    ImGui.cpp
    ImGuiContext.cpp
    ImGuiMainMenuBar.cpp
    ImGuiStyleColor.cpp
)

add_subdirectory(Element)
add_subdirectory(Renderer)
add_subdirectory(Window)
add_subdirectory(Wrapper)
