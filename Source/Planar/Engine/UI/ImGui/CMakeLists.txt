target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    ImGui.cpp
    ImGuiContext.cpp
    ImGuiElement.cpp
    ImGuiInputField.cpp
    ImGuiMainMenuBar.cpp
    ImGuiStyleColor.cpp
    ImGuiTextRenderer.cpp
    ImGuiWindow.cpp
)

add_subdirectory(Element)
add_subdirectory(Wrapper)
