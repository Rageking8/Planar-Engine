# Convert all `ARGN` from text to a `std::string` and place it
# in a new C++ file each, before adding to `target` as source
function(pack_text_to_string target)
    file(RELATIVE_PATH namespace ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})
    string(REPLACE "/" "::" namespace ${namespace})

    foreach (source_file ${ARGN})
        get_filename_component(source_name ${source_file} NAME_WLE)
        set(output_file ${CMAKE_CURRENT_BINARY_DIR}/${source_name}.cpp)

        file(READ ${source_file} file_data)
        string(REPLACE "\n" "\\n" file_data ${file_data})
        string(REPLACE "\"" "\\\"" file_data ${file_data})

        file(WRITE ${output_file}
"#include <string>

namespace Planar::${namespace}
{
    extern const std::string ${source_name} = \"${file_data}\";
}
"
        )

        target_sources(${target} PRIVATE ${output_file})
    endforeach()
endfunction()

# Helper function to `pack_binary_to_unsigned_char_array_chunk`
# that sets `chunk_size` to 0 which disables chunking
function(pack_binary_to_unsigned_char_array target)
    set(chunk_size 0)
    pack_binary_to_unsigned_char_array_macro(${ARGN})
endfunction()

# Convert all `ARGN` from binary to an unsigned char array. If
# `chunk_size` is more than 0, it represents the chunk size of
# the individual arrays, else chunking is disabled
function(pack_binary_to_unsigned_char_array_chunk target chunk_size)
    pack_binary_to_unsigned_char_array_macro(${ARGN})
endfunction()

# Implementation macro for `pack_binary_to_unsigned_char_array`
# and `pack_binary_to_unsigned_char_array_chunk` since calling
# `pack_binary_to_unsigned_char_array_chunk` in
# `pack_binary_to_unsigned_char_array` breaks current directory
# values
macro(pack_binary_to_unsigned_char_array_macro)
    file(RELATIVE_PATH namespace ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})
    string(REPLACE "/" "::" namespace ${namespace})

    foreach (binary_file ${ARGN})
        get_filename_component(binary_name ${binary_file} NAME_WLE)
        set(output_file ${CMAKE_CURRENT_BINARY_DIR}/${binary_name})

        file(READ ${binary_file} file_data HEX)
        string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1,"
            file_data ${file_data}
        )

        string(LENGTH ${file_data} file_length)
        set(chunk_id 0)
        set(file_index 0)

        while(${file_index} LESS ${file_length})
            math(EXPR chunk_id "${chunk_id} + 1")
            math(EXPR length_left "${file_length} - ${file_index}")

            if(${length_left} LESS ${chunk_size} OR
                ${chunk_size} LESS_EQUAL 0)
                string(SUBSTRING ${file_data} ${file_index} -1 chunk_data)
                set(file_index ${file_length})
            else()
                string(SUBSTRING ${file_data} ${file_index}
                    ${chunk_size} chunk_data
                )
                math(EXPR file_index "${file_index} + ${chunk_size}")
            endif()

            if(${chunk_size} LESS_EQUAL 0)
                set(current_output_file ${output_file}.cpp)
                set(current_array_name ${binary_name})
            else()
                set(current_output_file ${output_file}${chunk_id}.cpp)
                set(current_array_name ${binary_name}${chunk_id})
            endif()

            file(WRITE ${current_output_file}
"namespace Planar::${namespace}
{
    extern const unsigned char ${current_array_name}[] =
        {${chunk_data}};
}
"
            )

            target_sources(${target} PRIVATE ${current_output_file})
        endwhile()
    endforeach()
endmacro()
