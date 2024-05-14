target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    ImGui.hpp
    ImGuiContext.hpp
    ImGuiElement.hpp
    ImGuiInputField.hpp
    ImGuiMainMenuBar.hpp
    ImGuiStyleColor.hpp
    ImGuiWindow.hpp
    ImGuiWindowFlags.hpp
)

add_subdirectory(Macros)
add_subdirectory(Wrapper)
