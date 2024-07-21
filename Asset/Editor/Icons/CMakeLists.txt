set(PLANAR_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PLANAR_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

pack_binary_to_unsigned_char_array(${PLANAR_EDITOR_TARGET}
    FileIcon.png
    FolderIcon.png
    LeftArrowIcon.png
    PlayIcon.png
    StopIcon.png
)

unset(PLANAR_CURRENT_SOURCE_DIR)
unset(PLANAR_CURRENT_BINARY_DIR)
