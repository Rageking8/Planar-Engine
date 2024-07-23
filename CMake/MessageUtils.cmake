function(message)
    if(NOT PLANAR_SUPPRESS_EXTERNAL_MESSAGE)
        _message(${ARGN})
    endif()
endfunction()

function(planar_message)
    _message(${ARGN})
endfunction()
