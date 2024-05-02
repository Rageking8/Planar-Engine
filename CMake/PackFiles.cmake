# Convert all `ARGN` from text to a `std::string` and place it
# in a new C++ file each, before adding to `target` as source
function(pack_text_to_string target)
    file(RELATIVE_PATH namespace ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
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
