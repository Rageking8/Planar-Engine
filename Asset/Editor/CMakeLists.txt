set(CURRENT_ASSET_DIR ${PLANAR_ROOT_ASSET_DIR}/Editor)

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

if(EXISTS ${PLANAR_ROOT_ASSET_DIR}/PlanarEngine.dll)
    pack_binary_to_unsigned_char_array_chunk(${PLANAR_EDITOR_TARGET}
        10000000 ${PLANAR_ROOT_ASSET_DIR}/PlanarEngine.dll
    )
else()
    message(WARNING "Asset/PlanarEngine.dll not found, "
        "build PlanarEditor and reconfigure CMake"
    )
endif()

add_subdirectory(Icons)
add_subdirectory(Layout)
add_subdirectory(Project)
add_subdirectory(Script)
