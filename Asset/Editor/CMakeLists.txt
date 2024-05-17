pack_text_to_string(${PLANAR_EDITOR_TARGET}
    DefaultLayout.planarlayout
    Project.planar
    Scene.planarscene
)

if(EXISTS ${CMAKE_BINARY_DIR}/Asset/dotnet_sdk.zip)
    pack_binary_to_unsigned_char_array_chunk(${PLANAR_EDITOR_TARGET}
        5000000 ${CMAKE_BINARY_DIR}/Asset/dotnet_sdk.zip
    )
endif()
