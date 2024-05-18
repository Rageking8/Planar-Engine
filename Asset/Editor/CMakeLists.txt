pack_text_to_string(${PLANAR_EDITOR_TARGET}
    DefaultLayout.planarlayout
    Project.planar
    Scene.planarscene
)

if(NOT EXISTS ${CMAKE_BINARY_DIR}/Asset/Editor/dotnet_sdk1.cpp)
    pack_binary_to_unsigned_char_array_chunk(${PLANAR_EDITOR_TARGET}
        10000000 ${CMAKE_BINARY_DIR}/Asset/dotnet_sdk.zip
    )
else()
    set(chunk_id 1)

    while(EXISTS ${CMAKE_BINARY_DIR}/Asset/Editor/dotnet_sdk${chunk_id}.cpp)
        target_sources(${PLANAR_EDITOR_TARGET} PRIVATE
            ${CMAKE_BINARY_DIR}/Asset/Editor/dotnet_sdk${chunk_id}.cpp
        )
        math(EXPR chunk_id "${chunk_id} + 1")
    endwhile()
endif()
