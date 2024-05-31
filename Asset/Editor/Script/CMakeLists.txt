set(CURRENT_ASSET_DIR ${PLANAR_ROOT_ASSET_DIR}/Editor/Script)

if(EXISTS ${PLANAR_ROOT_ASSET_DIR}/PlanarScript.dll)
    pack_binary_to_unsigned_char_array(${PLANAR_EDITOR_TARGET}
        ${PLANAR_ROOT_ASSET_DIR}/PlanarScript.dll
    )
else()
    message(WARNING "Asset/PlanarScript.dll not found, "
        "build PlanarEditor and reconfigure CMake"
    )
endif()

pack_text_to_string(${PLANAR_EDITOR_TARGET}
    BaseProject.planarcsproj
    GeneratedEntry.planarcs
)
