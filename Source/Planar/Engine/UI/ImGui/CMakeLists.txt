target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    ImGui.cpp
    ImGuiContext.cpp
)

add_subdirectory(Element)
add_subdirectory(Menu)
add_subdirectory(Renderer)
add_subdirectory(Size)
add_subdirectory(Style)
add_subdirectory(Window)
add_subdirectory(Wrapper)
