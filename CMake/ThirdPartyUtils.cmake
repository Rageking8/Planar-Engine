function(copy_third_party_include third_party source)
    copy_single_source(
        ${${third_party}_SOURCE_DIR}/${source}
        ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/${third_party}
    )
endfunction()
