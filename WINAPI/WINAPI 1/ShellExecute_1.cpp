
// SHSTDAPI_(HINSTANCE) ShellExecute(
// __in_opt HWND hwnd,				// 指定父窗口句柄
// __in_opt LPCSTR lpOperation,		// 指定动作:open,runas,print,edit,explore,find[2]
// __in LPCSTR lpFile,				// 指定要打开的文件或程序
// __in_opt LPCSTR lpParameters,	// 参数，如果要打开的是文件这里应该是NULL
// __in_opt LPCSTR lpDirectory,		// 默认目录
// __in INT nShowCmd);				// 打开选项

//ShowCmd 参数可选值:SW_HIDE = 0; {隐藏}
//SW_SHOWNORMAL = 1; {用最近的大小和位置显示, 激活}
//SW_NORMAL = 1; {同 SW_SHOWNORMAL}
//SW_SHOWMINIMIZED = 2; {最小化, 激活}
//SW_SHOWMAXIMIZED = 3; {最大化, 激活}
//SW_MAXIMIZE = 3; {同 SW_SHOWMAXIMIZED}
//SW_SHOWNOACTIVATE = 4; {用最近的大小和位置显示, 不激活}
//SW_SHOW = 5; {同 SW_SHOWNORMAL}
//SW_MINIMIZE = 6; {最小化, 不激活}
//SW_SHOWMINNOACTIVE = 7; {同 SW_MINIMIZE}
//SW_SHOWNA = 8; {同 SW_SHOWNOACTIVATE}
//SW_RESTORE = 9; {同 SW_SHOWNORMAL}
//SW_SHOWDEFAULT = 10; {同 SW_SHOWNORMAL}
//SW_MAX = 10; {同 SW_SHOWNORMAL}

// 执行成功会返回应用程序句柄
// 返回的HINSTANCE可以将它转换为一个整数(%d)，并比较它的值大于还是小于32或比较它的错误代码
// 返回值大于32表示执行成功
// 返回值小于32表示执行错误
// 返回值可能的错误有: = 0 {内存不足}
// ERROR_FILE_NOT_FOUND = 2; {文件名错误}
// ERROR_PATH_NOT_FOUND = 3; {路径名错误}
// ERROR_BAD_FORMAT = 11; {EXE 文件无效}
// SE_ERR_SHARE = 26; {发生共享错误}
// SE_ERR_ASSOCINCOMPLETE = 27; {文件名不完全或无效}
// SE_ERR_DDETIMEOUT = 28; {超时}
// SE_ERR_DDEFAIL = 29; {DDE 事务失败}
// SE_ERR_DDEBUSY = 30; {正在处理其他 DDE 事务而不能完成该 DDE 事务}
// SE_ERR_NOASSOC = 31; {没有相关联的应用程序}

#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <ShellAPI.h>

using std::cout;
using std::endl;

int main()
{
	ShellExecute(NULL, _T("open"), _T("calc.exe"), NULL, NULL, SW_SHOWNORMAL);
	ShellExecute(NULL, _T("open"), _T("notepad.exe"), NULL, NULL, SW_SHOWNORMAL);

	system("pause");
	return 0;
}