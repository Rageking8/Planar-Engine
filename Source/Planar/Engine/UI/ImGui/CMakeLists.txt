target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    ImGui.cpp
    ImGuiContext.cpp
    ImGuiStyleColor.cpp
)

add_subdirectory(Element)
add_subdirectory(Menu)
add_subdirectory(Renderer)
add_subdirectory(Style)
add_subdirectory(Window)
add_subdirectory(Wrapper)
