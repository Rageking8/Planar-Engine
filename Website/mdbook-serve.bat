@echo off

where /q mdbook
if errorlevel 1 (
    echo [31mmdbook.exe not found[0m
    echo:
    pause
    exit /b 1
)

mdbook serve -o

if errorlevel 1 (
    echo:
    echo [31mmdbook serve failed[0m
    echo:
    pause
    exit /b 1
)
