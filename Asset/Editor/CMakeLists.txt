pack_text_to_string(${PLANAR_EDITOR_TARGET}
    DefaultLayout.planarlayout
    Project.planar
    Scene.planarscene
)

if(EXISTS ${CMAKE_BINARY_DIR}/Asset/dotnet_sdk.zip AND
    NOT EXISTS ${CMAKE_BINARY_DIR}/Asset/Editor/dotnet_sdk1.cpp)
    pack_binary_to_unsigned_char_array_chunk(${PLANAR_EDITOR_TARGET}
        10000000 ${CMAKE_BINARY_DIR}/Asset/dotnet_sdk.zip
    )
endif()
