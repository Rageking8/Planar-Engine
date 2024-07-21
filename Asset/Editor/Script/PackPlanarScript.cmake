cmake_minimum_required(VERSION 3.15..3.29 FATAL_ERROR)

include(${PLANAR_SOURCE_DIR}/CMake/PackFiles.cmake)

set(skip_target_sources ON)

pack_binary_to_unsigned_char_array(${PLANAR_EDITOR_TARGET}
    ${PLANAR_ROOT_ASSET_DIR}/PlanarScript.dll
)
