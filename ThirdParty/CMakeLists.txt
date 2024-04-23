include(FetchContent)

set(PLANAR_EXTERNAL_THIRD_PARTY_INCLUDES_DIR
    "${PLANAR_EXTERNAL_INCLUDES_DIR}/ThirdParty"
)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_HASH 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 # 3.4
)

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_HASH 231cbee0fc4f59dbe5b8b853a11b08dc84e57c65 # 1.90.5
)

add_subdirectory(glad)
add_subdirectory(GLFW)
add_subdirectory(ImGui)
add_subdirectory(KHR)
