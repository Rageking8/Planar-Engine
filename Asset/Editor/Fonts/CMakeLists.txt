message(STATUS "Downloading Roboto")

file(DOWNLOAD
    https://fonts.gstatic.com/s/roboto/v30/KFOmCnqEu92Fr1Me5WZLCzYlKw.ttf
    ${PLANAR_ROOT_ASSET_DIR}/Roboto.ttf
    EXPECTED_HASH
        SHA256=4E147AB64B9FDF6D89D01F6B8C3CA0B3CDDC59D608A8E2218F9A2504B5C98E14
)

pack_binary_to_unsigned_char_array(${PLANAR_EDITOR_TARGET}
    ${PLANAR_ROOT_ASSET_DIR}/Roboto.ttf
)
