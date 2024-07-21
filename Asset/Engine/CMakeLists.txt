set(CURRENT_ASSET_DIR ${PLANAR_ROOT_ASSET_DIR}/Engine)

pack_text_to_string(${PLANAR_ENGINE_OBJECT_TARGET}
    BasicPrelude.planarprelude
)

set(PLANAR_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PLANAR_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

if(NOT EXISTS ${CURRENT_ASSET_DIR}/_7zr.cpp)
    pack_binary_to_unsigned_char_array(${PLANAR_ENGINE_OBJECT_TARGET}
        ${PLANAR_ROOT_ASSET_DIR}/_7zr.exe
    )
else()
    target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
        ${CURRENT_ASSET_DIR}/_7zr.cpp
    )
endif()

unset(PLANAR_CURRENT_SOURCE_DIR)
unset(PLANAR_CURRENT_BINARY_DIR)

add_subdirectory(Graphics)
