include(FetchContent)

FetchContent_Declare(
    GLFW
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_HASH 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 # 3.4
)

set(PLANAR_FETCHED_THIRD_PARTY_INCLUDES_DIR
    "${PLANAR_FETCHED_INCLUDES_DIR}/ThirdParty")

add_subdirectory(GLFW) 
