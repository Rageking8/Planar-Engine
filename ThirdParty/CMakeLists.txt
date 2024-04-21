include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_HASH 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 # 3.4
)

set(PLANAR_EXTERNAL_THIRD_PARTY_INCLUDES_DIR
    "${PLANAR_EXTERNAL_INCLUDES_DIR}/ThirdParty")

add_subdirectory(glad)
add_subdirectory(GLFW)
add_subdirectory(KHR)
