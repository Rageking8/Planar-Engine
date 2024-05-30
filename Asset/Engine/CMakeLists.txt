pack_text_to_string(${PLANAR_ENGINE_OBJECT_TARGET}
    BasicPrelude.planarprelude
)

if(NOT EXISTS ${CMAKE_BINARY_DIR}/Asset/Engine/_7zr.cpp)
    pack_binary_to_unsigned_char_array(${PLANAR_ENGINE_OBJECT_TARGET}
        ${CMAKE_BINARY_DIR}/Asset/_7zr.exe
    )
else()
    target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
        ${CMAKE_BINARY_DIR}/Asset/Engine/_7zr.cpp
    )
endif()

add_subdirectory(Graphics)
