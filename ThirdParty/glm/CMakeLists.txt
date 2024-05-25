message(STATUS "Fetching glm")

FetchContent_MakeAvailable(glm)

file(COPY ${glm_SOURCE_DIR}/glm/ DESTINATION
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/glm
    PATTERN "CMakeLists.txt" EXCLUDE
)
