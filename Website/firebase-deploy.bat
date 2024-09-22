@echo off

call check-livereload

if %errorlevel%==1 (
    echo:
    pause
    exit /b 1
)

cmd /c firebase deploy

echo:
pause
exit /b 0
