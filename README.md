# Planar Engine

A 2D Game Engine.

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
    - [glad](https://github.com/Dav1dde/glad) - OpenGL loader
    - [GLFW](https://github.com/glfw/glfw) - Window, Input, OpenGL context
    - [Dear ImGui](https://github.com/ocornut/imgui) - Editor UI
    - [yaml-cpp](https://github.com/jbeder/yaml-cpp) - Assets
    - [stb](https://github.com/nothings/stb) - Image loader
    - [glm](https://github.com/g-truc/glm) - Computer graphics types and routines
    - [reproc](https://github.com/DaanDeMeyer/reproc) - Create and manage processes
    - [LZMA SDK](https://www.7-zip.org/sdk.html) - Compress and extract 7z archives
    - [nativefiledialog-extended](https://github.com/btzy/nativefiledialog-extended) - Select file and folder dialog
    - [SoLoud](https://github.com/jarikomppa/soloud) - Audio

1. Planar Editor
    - Planar Engine - All core routines
    - [.NET SDK](https://dotnet.microsoft.com/en-us/download) - Build and publish C# projects
    - [UPX](https://github.com/upx/upx) - Compress EXE and DLL

1. Website
    - [mdBook](https://github.com/rust-lang/mdBook) - Website and documentation
