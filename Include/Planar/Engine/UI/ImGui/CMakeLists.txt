target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    ImGui.hpp
    ImGuiContext.hpp
    ImGuiMainMenuBar.hpp
    ImGuiStyleColor.hpp
    ImGuiTextRenderer.hpp
)

add_subdirectory(Element)
add_subdirectory(Macros)
add_subdirectory(Window)
add_subdirectory(Wrapper)
