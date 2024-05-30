target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    ImGui.hpp
    ImGuiContext.hpp
)

add_subdirectory(Element)
add_subdirectory(Macros)
add_subdirectory(Menu)
add_subdirectory(Renderer)
add_subdirectory(Style)
add_subdirectory(Window)
add_subdirectory(Wrapper)
