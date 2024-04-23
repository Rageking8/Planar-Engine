function(get_all_target_list target_list)
    set(current_list)
    get_targets_recursive(current_list ${CMAKE_CURRENT_SOURCE_DIR})
    set(${target_list} ${current_list} PARENT_SCOPE)
endfunction()

macro(get_targets_recursive current_list dir)
    get_property(subdirectories DIRECTORY ${dir} PROPERTY SUBDIRECTORIES)

    foreach(subdir ${subdirectories})
        get_targets_recursive(${current_list} ${subdir})
    endforeach()

    get_property(result DIRECTORY ${dir} PROPERTY BUILDSYSTEM_TARGETS)
    list(APPEND ${current_list} ${result})
endmacro()
