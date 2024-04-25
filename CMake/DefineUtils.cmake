# Define `ARGN` with scope `scope` for `target` if `check_target`
# has type `type`
function(define_if_check_target_type target check_target scope type)
    get_target_property(check_target_type ${check_target} TYPE)

    if(check_target_type STREQUAL type)
        target_compile_definitions(${target} ${scope} ${ARGN})
    endif()
endfunction()

# Define `ARGN` with scope `scope` for `target` if `target`
# has type `STATIC_LIBRARY`
function(define_if_target_static target scope)
    define_if_check_target_type(${target} ${target} ${scope}
        STATIC_LIBRARY ${ARGN})
endfunction()

# Define `ARGN` with scope `scope` for `target` if `target`
# has type `SHARED_LIBRARY`
function(define_if_target_shared target scope)
    define_if_check_target_type(${target} ${target} ${scope}
        SHARED_LIBRARY ${ARGN})
endfunction()

# Define `ARGN` with scope `scope` for `target` if `target`
# has type `EXECUTABLE`
function(define_if_target_executable target scope)
    define_if_check_target_type(${target} ${target} ${scope}
        EXECUTABLE ${ARGN})
endfunction()

# Define `ARGN` with scope `scope` for `target` if `check_target`
# has type `STATIC_LIBRARY`
function(define_if_check_target_static target check_target scope)
    define_if_check_target_type(${target} ${check_target} ${scope}
        STATIC_LIBRARY ${ARGN})
endfunction()

# Define `ARGN` with scope `scope` for `target` if `check_target`
# has type `SHARED_LIBRARY`
function(define_if_check_target_shared target check_target scope)
    define_if_check_target_type(${target} ${check_target} ${scope}
        SHARED_LIBRARY ${ARGN})
endfunction()

# Define `ARGN` with scope `scope` for `target` if `check_target`
# has type `EXECUTABLE`
function(define_if_check_target_executable target check_target scope)
    define_if_check_target_type(${target} ${check_target} ${scope}
        EXECUTABLE ${ARGN})
endfunction()
