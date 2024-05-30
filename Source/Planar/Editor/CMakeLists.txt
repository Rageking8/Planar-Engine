add_executable(${PLANAR_EDITOR_TARGET})

target_link_libraries(${PLANAR_EDITOR_TARGET} PRIVATE
    ${PLANAR_ENGINE_${PLANAR_EDITOR_LINK_ENGINE}_TARGET}
)

add_dependencies(${PLANAR_EDITOR_TARGET}
    ${PLANAR_ENGINE_SHARED_TARGET}
)

target_include_directories(${PLANAR_EDITOR_TARGET} PRIVATE
    ${PLANAR_INCLUDE_ROOT_DIR}
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
    ${PLANAR_ASSET_INCLUDE_DIR}
)

if(MSVC)
    target_compile_options(${PLANAR_EDITOR_TARGET} PRIVATE
        /Zc:preprocessor
    )

    set_target_properties(${PLANAR_EDITOR_TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/Source/Planar/Editor/$<0:>
    )
endif()

if(${PLANAR_EDITOR_LINK_ENGINE} STREQUAL SHARED)
    target_compile_definitions(${PLANAR_EDITOR_TARGET} PRIVATE
        PLANAR_ENABLE_EXPORT
    )
endif()

add_subdirectory(Core)
add_subdirectory(Entry)
add_subdirectory(Project)
add_subdirectory(Scene)
add_subdirectory(Script)
add_subdirectory(UI)
