@echo off

where /q mdbook
if errorlevel 1 (
    @echo mdbook.exe not found
    @echo:
    pause
    exit /b 1
)

mdbook serve -o
