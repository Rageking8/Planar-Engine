# Add `prefix` to all lists in `ARGN`
function(prepend_lists prefix)
    foreach(list ${ARGN})
        set(new_list ${${list}})
        list(TRANSFORM new_list PREPEND ${prefix})
        set(${list} ${new_list} PARENT_SCOPE)
    endforeach()
endfunction()
