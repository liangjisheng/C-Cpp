
// ShellExecute的功能是运行一个外部程序（或者是打开一个已注册的文件、打开一个目录、打印一个文件等等），
// 并对外部程序有一定的控制。有几个API函数都可以实现这些功能，但是在大多数情况下ShellExecute是更多的被使用的，
// 同时它并不是太复杂。

//HINSTANCE ShellExecute(
		// hWnd: HWND;			// {指定父窗口句柄}
		// Operation: PChar;	// {指定动作, 譬如: open、runas、print、edit、explore、find[2]  }
		// FileName: PChar;		// {指定要打开的文件或程序}
		// Parameters: PChar;	// {给要打开的程序指定参数; 如果打开的是文件这里应该是 nil}
		// Directory: PChar;	// {缺省目录}
		// ShowCmd: Integer		// {打开选项}
		// );

// ShowCmd 参数可选值:SW_HIDE = 0; {隐藏}
// SW_SHOWNORMAL = 1; {用最近的大小和位置显示, 激活}
// SW_NORMAL = 1; {同 SW_SHOWNORMAL}
// SW_SHOWMINIMIZED = 2; {最小化, 激活}
// SW_SHOWMAXIMIZED = 3; {最大化, 激活}
// SW_MAXIMIZE = 3; {同 SW_SHOWMAXIMIZED}
// SW_SHOWNOACTIVATE = 4; {用最近的大小和位置显示, 不激活}
// SW_SHOW = 5; {同 SW_SHOWNORMAL}
// SW_MINIMIZE = 6; {最小化, 不激活}
// SW_SHOWMINNOACTIVE = 7; {同 SW_MINIMIZE}
// SW_SHOWNA = 8; {同 SW_SHOWNOACTIVATE}
// SW_RESTORE = 9; {同 SW_SHOWNORMAL}
// SW_SHOWDEFAULT = 10; {同 SW_SHOWNORMAL}
// SW_MAX = 10; {同 SW_SHOWNORMAL}

// 成功返回应用程序句柄，失败使用GetLastError()查看值


#include <iostream>
#include <Windows.h>
#include <shellapi.h>
#include <tchar.h>

#pragma comment(lib, "Shell32.lib")

using namespace std;


int main()
{
	HINSTANCE h1 = NULL;
	h1 = ShellExecute(0, _T("open"), _T("calc.exe"), _T(""), _T(""), SW_SHOWNORMAL);
	cout << (int)h1 << endl;
 	if(32 < (int)h1)
		cout << "succeed" << endl;
	else
		cout << "failed" << endl;
	cout << endl;

	cout << "Opening with WinExec" << endl;
	if(WinExec("notepad readme.txt", SW_SHOWNORMAL) < 32)
		cout << "WinExec error" << endl;
	else
		cout << "WinExec error" << endl;

	system("dir");
	system("pause");
	return 0;
}