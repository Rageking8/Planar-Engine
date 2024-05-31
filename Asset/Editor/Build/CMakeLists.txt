set(CURRENT_ASSET_DIR ${PLANAR_ROOT_ASSET_DIR}/Editor/Build)

if(NOT EXISTS ${CURRENT_ASSET_DIR}/upx.cpp)
    pack_binary_to_unsigned_char_array(${PLANAR_EDITOR_TARGET}
        ${PLANAR_ROOT_ASSET_DIR}/upx.exe
    )
else()
    target_sources(${PLANAR_EDITOR_TARGET} PRIVATE
        ${CURRENT_ASSET_DIR}/upx.cpp
    )
endif()
