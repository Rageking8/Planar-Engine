function(define_if_type target scope type)
    get_target_property(target_type ${target} TYPE)

    if(target_type STREQUAL type)
        target_compile_definitions(${target} ${scope} ${ARGN})
    endif()
endfunction()

function(define_if_static target scope)
    define_if_type(${target} ${scope} STATIC_LIBRARY ${ARGN})
endfunction()

function(define_if_shared target scope)
    define_if_type(${target} ${scope} SHARED_LIBRARY ${ARGN})
endfunction()

function(define_if_executable target scope)
    define_if_type(${target} ${scope} EXECUTABLE ${ARGN})
endfunction()
