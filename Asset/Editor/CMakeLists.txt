set(CURRENT_ASSET_DIR ${PLANAR_ROOT_ASSET_DIR}/Editor)

set(PLANAR_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PLANAR_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

if(NOT EXISTS ${CURRENT_ASSET_DIR}/dotnet_sdk1.cpp)
    pack_binary_to_unsigned_char_array_chunk(${PLANAR_EDITOR_TARGET}
        10000000 ${PLANAR_ROOT_ASSET_DIR}/dotnet_sdk.7z
    )
else()
    set(chunk_id 1)

    while(EXISTS ${CURRENT_ASSET_DIR}/dotnet_sdk${chunk_id}.cpp)
        target_sources(${PLANAR_EDITOR_TARGET} PRIVATE
            ${CURRENT_ASSET_DIR}/dotnet_sdk${chunk_id}.cpp
        )
        math(EXPR chunk_id "${chunk_id} + 1")
    endwhile()
endif()

unset(PLANAR_CURRENT_SOURCE_DIR)
unset(PLANAR_CURRENT_BINARY_DIR)

add_subdirectory(Build)
add_subdirectory(Fonts)
add_subdirectory(Icons)
add_subdirectory(Layout)
add_subdirectory(Project)
add_subdirectory(Script)
add_subdirectory(Textures)
