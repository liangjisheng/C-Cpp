::批处理一般用两个冒号注释

::用两个冒号注释不会回显在窗口上

::rem注释默认回显在窗口上，使用echo off可以关闭

::两个百分号也可以注释，默认不回显

%注释内容%

::加上@后命令不回显

@echo off

rem 也可以用rem命令注释

:: 默认情况下返回应用程序存储数据的位置
echo %APPDATA%

:: 返回当前目录的字符串
echo %CD%s

:: %cd% 和 %~dp0都可以显示路径
:: %cd%的内容是可以改变的，其内容为命令的执行路径或批处理文件的执行路径
:: %~dp0只可以用在批处理文件中，他由批处理文件所在的目录位置决定，内容不能改变

echo this is %%cd%% %cd%

::0代表批处理本身
echo this is %%~dp0 %~dp0

echo -e "abc\ndef"

pause