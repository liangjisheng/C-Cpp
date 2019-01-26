
@echo off
::下一行代码运行同一目录下的exe程序
0813-1.exe
if %ERRORLEVEL% == 3 echo third
if %ERRORLEVEL% == 2 echo second
if %ERRORLEVEL% == 1 echo first

pause