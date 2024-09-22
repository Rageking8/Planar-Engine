@echo off

set exit_code=0

for /r %%f in (*.html) do (
    >nul find "Livereload" %%f && (
        set exit_code=1
        goto :end
    )
)

:end

if %exit_code%==0 (
    echo [92mLivereload check succeeded, no livereload script found.[0m
) else (
    echo [31mLivereload check failed, livereload script found.[0m
)

echo %cmdcmdline% | find /i "%~0" >nul
if %errorlevel%==0 (
    echo:
    pause
)

exit /b %exit_code%
