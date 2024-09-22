# Planar Engine

A 2D Game Engine.

![Editor user interface in a demo project](https://github.com/user-attachments/assets/60107d2d-ddb8-434a-a34d-c14152b16bfd)

## Contents

1. [Build](#build)
    - [Requirements](#requirements)
    - [Support](#support)
1. [Project Structure](#project-structure)
1. [Dependencies](#dependencies)

## Build

### Requirements

- C++20
- .NET 8 (C# 12)
- Visual Studio 2022 with C++ CMake tools for Windows

### Support

Currently Windows is the only operating system supported.

## Project Structure

| Directory                                                                     | Description                                                                                                                                                                                                           |
| ----------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [Asset](https://github.com/Rageking8/Planar-Engine/tree/main/Asset)           | Assets that are used by core components                                                                                                                                                                               |
| [CMake](https://github.com/Rageking8/Planar-Engine/tree/main/CMake)           | CMake utility modules                                                                                                                                                                                                 |
| [Include](https://github.com/Rageking8/Planar-Engine/tree/main/Include)       | Header and template implementations for [Engine](https://github.com/Rageking8/Planar-Engine/tree/main/Include/Planar/Engine) and [Editor](https://github.com/Rageking8/Planar-Engine/tree/main/Include/Planar/Editor) |
| [Script](https://github.com/Rageking8/Planar-Engine/tree/main/Script)         | C# scripting interface                                                                                                                                                                                                |
| [Source](https://github.com/Rageking8/Planar-Engine/tree/main/Source)         | Source for [Engine](https://github.com/Rageking8/Planar-Engine/tree/main/Source/Planar/Engine) and [Editor](https://github.com/Rageking8/Planar-Engine/tree/main/Source/Planar/Editor)                                |
| [ThirdParty](https://github.com/Rageking8/Planar-Engine/tree/main/ThirdParty) | CMake scripts used to fetch dependencies and contains a few third party source files                                                                                                                                  |
| [Website](https://github.com/Rageking8/Planar-Engine/tree/main/Website)       | Source for website hosted using [Firebase Hosting](https://firebase.google.com/docs/hosting)                                                                                                                          |

## Dependencies

1. Planar Engine
    - [Dav1dde/glad](https://github.com/Dav1dde/glad) - OpenGL loader
    - [glfw/glfw](https://github.com/glfw/glfw) - Window, Input, OpenGL context
    - [ocornut/imgui](https://github.com/ocornut/imgui) - Editor UI
    - [jbeder/yaml-cpp](https://github.com/jbeder/yaml-cpp) - Assets
    - [nothings/stb](https://github.com/nothings/stb) - Image loader
    - [g-truc/glm](https://github.com/g-truc/glm) - Computer graphics types and routines
    - [btzy/nativefiledialog-extended](https://github.com/btzy/nativefiledialog-extended) - Select file and folder dialog
    - [jarikomppa/soloud](https://github.com/jarikomppa/soloud) - Audio

1. Planar Editor
    - Planar Engine - All core routines
    - [.NET SDK](https://dotnet.microsoft.com/en-us/download) - Build and publish C# projects
    - [upx/upx](https://github.com/upx/upx) - Compress EXE and DLL
    - [LZMA SDK](https://www.7-zip.org/sdk.html) - Compress and extract 7z archives
    - [DaanDeMeyer/reproc](https://github.com/DaanDeMeyer/reproc) - Create and manage processes
    - [p-ranav/argparse](https://github.com/p-ranav/argparse) - Parse command line arguments

1. Website
    - [rust-lang/mdBook](https://github.com/rust-lang/mdBook) - Website and documentation
