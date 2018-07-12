
// 使用系统API接口去修改控制台的文字和背景颜色

// 得到 standard input,standard output, standard error 的设备句柄
// HANDLE GetStdHandle(DWORD nStdHandle);
// 参数有STD_INPUT_HANDLE,STD_OUTPUT_HANDLE及STD_ERROR_HANDLE

// 设置控制台设备的属性
// BOOL SetConsoleTextAttribute( HANDLE hConsoleOutput,WORD wAttributes);
// 第一个参数为控制台standard input, standard output, or standard error的设备句柄
// 第二个参数用来设备设备的属性，这里详细介绍下表示颜色的参数

// 先看下颜色的种类：
// 在XP系统 控制台一共有16种文字颜色，16种背景颜色，可以通过
// 文字颜色 + 背景颜色 * 0x10 来设置控制台的颜色。

// 已经定义好的颜色常量如下：
// 文字颜色使用如下组合：
// FOREGROUND_BLUE      0x0001 // text color contains blue.
// FOREGROUND_GREEN     0x0002 // text color contains green.
// FOREGROUND_RED       0x0004 // text color contains red.
// FOREGROUND_INTENSITY 0x0008 // text color is intensified.高亮颜色
// 背景颜色使用如下组合（其实就是上面值*0x10）：
// BACKGROUND_BLUE      0x0010 // background color contains blue.
// BACKGROUND_GREEN    0x0020 // background color contains green.
// BACKGROUND_RED       0x0040 // background color contains red.
// BACKGROUND_INTENSITY 0x0080 // background color is intensified.
// 上面的颜色可以任意组合，如知道黄色可以由红色和绿色组成，
// 所以可以用FOREGROUND_GREEN | FOREGROUND_RED来表示黄色的文字。
//
// 默认情况下控制台的文字颜色是白色即用
// FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE也可以直接用7表示，
// 背景颜色为黑色即用0表示

#include <stdio.h>
#include <Windows.h>

// 一共有16种文字颜色，16种背景颜色，组合有256种。传入的值应当小于256 
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}


int main()
{
	printf("控制台下默认文字背景颜色:\n");
	printf("MoreWindows\n");
	printf("--------------------------------------\n\n");

	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	printf("控制台下红字蓝底:\n");
	printf("MoreWindows\n");
	printf("--------------------------------------\n\n");

	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("还原为控制台下默认文字背景颜色:\n");
	printf("MoreWindows\n");
	printf("--------------------------------------\n\n");

	getchar();
	return 0;
}