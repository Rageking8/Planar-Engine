add_executable(${PLANAR_SCRIPT_TARGET})

target_compile_options(${PLANAR_SCRIPT_TARGET} PRIVATE
    "/langversion:12.0"
)

set_target_properties(${PLANAR_SCRIPT_TARGET} PROPERTIES
    DOTNET_SDK "Microsoft.NET.Sdk"
    DOTNET_TARGET_FRAMEWORK "net8.0"
)

set_property(TARGET ${PLANAR_SCRIPT_TARGET} PROPERTY
    VS_PACKAGE_REFERENCES " "
)

if(MSVC)
    set_target_properties(${PLANAR_SCRIPT_TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/Script/$<0:>
    )
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/.vs)
    file(WRITE ${CMAKE_SOURCE_DIR}/.vs/launch.vs.json
    [=[
{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "coreclr",
      "project": "CMakeLists.txt",
      "projectTarget": "PlanarScript.exe (Script\\PlanarScript.exe)",
      "name": "PlanarScript.exe (Script\\PlanarScript.exe)"
    }
  ]
}
    ]=])
endif()

add_subdirectory(Planar)
