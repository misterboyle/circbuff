@set "PATH=%PATH%;%MW_MINGW64_LOC%\bin"

if "%1"=="" ("mingw32-make"  -f makefile clean circbuff) else ("mingw32-make"  -f makefile %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
