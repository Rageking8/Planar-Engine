function(copy_single_source source)
    foreach(destination ${ARGN})
        file(COPY ${source} DESTINATION ${destination})
    endforeach()
endfunction()
