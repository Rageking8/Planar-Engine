add_executable(${PLANAR_EDITOR_TARGET})

target_link_libraries(${PLANAR_EDITOR_TARGET} PRIVATE
    ${PLANAR_ENGINE_TARGET}
)

target_include_directories(${PLANAR_EDITOR_TARGET} PRIVATE
    ${PLANAR_INCLUDE_ROOT_DIR}
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

if(MSVC)
    set_target_properties(${PLANAR_EDITOR_TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/Source/Planar/Editor/$<0:>
    )
endif()

define_if_check_target_shared(${PLANAR_EDITOR_TARGET}
    ${PLANAR_ENGINE_TARGET} PRIVATE
    PLANAR_ENABLE_EXPORT
)

add_subdirectory(Core)
add_subdirectory(Entry)
add_subdirectory(Project)
add_subdirectory(Scene)
add_subdirectory(UI)
