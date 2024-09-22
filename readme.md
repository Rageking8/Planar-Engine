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
    - [Dav1dde/glad](https://github.com/Dav1dde/glad) ([2.0.6](https://github.com/Dav1dde/glad/releases/tag/v2.0.6)) - OpenGL loader
    - [glfw/glfw](https://github.com/glfw/glfw) ([3.4](https://github.com/glfw/glfw/releases/tag/3.4)) - Window, Input, OpenGL context
    - [ocornut/imgui](https://github.com/ocornut/imgui) ([1.91.0-docking](https://github.com/ocornut/imgui/releases/tag/v1.91.0-docking)) - Editor UI
    - [jbeder/yaml-cpp](https://github.com/jbeder/yaml-cpp) ([0.8.0](https://github.com/jbeder/yaml-cpp/releases/tag/0.8.0)) - Assets
    - [nothings/stb](https://github.com/nothings/stb) ([ae721c50](https://github.com/nothings/stb/commit/ae721c50eaf761660b4f90cc590453cdb0c2acd0)) - Image loader
    - [g-truc/glm](https://github.com/g-truc/glm) ([1.0.1](https://github.com/g-truc/glm/releases/tag/1.0.1)) - Computer graphics types and routines
    - [btzy/nativefiledialog-extended](https://github.com/btzy/nativefiledialog-extended) ([1.2.0](https://github.com/btzy/nativefiledialog-extended/releases/tag/v1.2.0)) - Select file and folder dialog
    - [jarikomppa/soloud](https://github.com/jarikomppa/soloud) ([799c535e](https://github.com/jarikomppa/soloud/commit/799c535efcf47bb2b440f809b21b4d72e2a8b4b0)) - Audio

1. Planar Editor
    - Planar Engine - All core routines
    - [.NET SDK](https://dotnet.microsoft.com/en-us/download) (8.0.300) - Build and publish C# projects
    - [upx/upx](https://github.com/upx/upx) ([4.2.4](https://github.com/upx/upx/releases/tag/v4.2.4)) - Compress EXE and DLL
    - [LZMA SDK](https://www.7-zip.org/sdk.html) (24.06) - Compress and extract 7z archives
    - [DaanDeMeyer/reproc](https://github.com/DaanDeMeyer/reproc) ([14.2.5](https://github.com/DaanDeMeyer/reproc/releases/tag/v14.2.5)) - Create and manage processes
    - [p-ranav/argparse](https://github.com/p-ranav/argparse) ([3.1](https://github.com/p-ranav/argparse/releases/tag/v3.1)) - Parse command line arguments

1. Website
    - [rust-lang/mdBook](https://github.com/rust-lang/mdBook) ([0.4.40](https://github.com/rust-lang/mdBook/releases/tag/v0.4.40)) - Website and documentation
