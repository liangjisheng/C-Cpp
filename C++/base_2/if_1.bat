@ echo off

set /p var1 = 请输入第一个比较的字符:
set /p var2 = 请输入第二个比较的字符:

if "%var1%" == "%var2%" (echo 输入的两个字符相等) else echo 输入的两个字符不等

:: 如果想忽略大小写，则加上/i参数

if "test" == "test" echo equal_1

if 1234 equ 1234 echo equal_2

if exist test1.bat echo test1.bat is exist

if defined Path echo Path has defined

if /i "test" == "TEST" (echo asdf) else (echo asdfasdf)

if "test" == "TEST" (echo asdf) else (echo asdfasdf)


pause