
// 创建一个新进程来运行指定的另一个可执行程序。CreateProcess()创建一个
// 新进程和其主线程，以运行指定(路径/文件名或命令行)的应用程序.

// 成功返回非0，失败返回0，可用GetLastError()返回出错的代码
//BOOL CreateProcess(
	//LPCTSTR lpApplicationName,		// 可执行文件的全路径或文件名，有命令行时可为NULL
	//LPTSTR lpCommandLine,			// 命令行参数，有可应用名时可为NULL
	//LPSECURITY_ATTRIBUTES lpProcessAttributes,	// 进程的安全属性,NULL表示默认安全
	//LPSECURITY_ATTRIBUTES lpThreadAttributes,	// 主线程的安全属性，NULL表示默认安全
	//BOOL bInheritHandles,	// 子进程是否继承新进程的句柄
	//DWORD dwCreateFlags,	// 创建标志，用于设置进程的创建状态和优先级别，可为NULL
	//LPVOID lpEnvironment,	// 环境变量，为NULL时，同当前进程的
	//LPCTSTR lpCurrentDirectory,	// 进程运行的当前目录，为NULL时同当前进程的
	//LPSTARTUPINFO lpStartupInfo,	// 指向设置进程主窗口或控制条的各种属性的结构指针
	//LPPROCESS_INFORMATION lpProcessInformation	// 指向返回进程信息的结构指针
	//);


//结构STARTUPINFO和PROCESS_INFORMATION的定义分别为： 
//	typedef struct _STARTUPINFO { 
		//DWORD cb;					//  结构的长度（字节数） 
		//LPTSTR lpReserved;		//  保留，必须为NULL 
		//LPTSTR lpDesktop;			//  桌面-窗口站的名称 
		//LPTSTR lpTitle;			//  控制台进程的标题 
		//DWORD dwX;				//  窗口位置的横坐标 
		//DWORD dwY;				//  窗口位置的纵坐标 
		//DWORD dwXSize;			//  窗口的水平尺寸 
		//DWORD dwYSize;			//  窗口的垂直尺寸 
		//DWORD dwXCountChars;		//  控制台窗口的屏幕缓冲区宽度（字符数） 
		//DWORD dwYCountChars;		//  控制台窗口的屏幕缓冲区高度（字符数） 
		//DWORD dwFillAttribute;	//  控制台窗口的初始文本和背景色 
		//DWORD dwFlags;			//  窗口的创建标志 
		//WORD wShowWindow;			//  用作窗口显示函数ShowWindow的缺省参数 
		//WORD cbReserved2;			//  保留，必须为0 
		//LPBYTE lpReserved2;		//  保留，必须为NULL 
		//HANDLE hStdInput;			//  标准输入的句柄 
		//HANDLE hStdOutput;		//  标准输出的句柄 
		//HANDLE hStdError;			//  标准错误的句柄 
//} STARTUPINFO,    *LPSTARTUPINFO; 


//typedef struct _PROCESS_INFORMATION { 
		//HANDLE hProcess;			//  返回的进程句柄 
		//HANDLE hThread;			//  返回的主线程句柄 
		//DWORD dwProcessId;		//  返回的进程ID 
		//DWORD dwThreadId;			//  返回的主线程ID 
//} PROCESS_INFORMATION, *LPPROCESS_INFORMATION; 


// 处理可从创建进程函数CreateProcess的最后一个参数进程信息结构PROCESS_INFORMATION
// 变量来获取所创建的新进程及其主线程的句柄和ID外，还可利用API函数
// GetCurrentProcess和GetCurrentProcessId 来获取当前进程的句柄和ID： 
// HANDLE GetCurrentProcess(void); 
// DWORD GetCurrentProcessId(void); 
// 不过用GetCurrentProcess返回的是一个伪句柄，只能在当前进程中使用。
// 可以调用API函数DuplicateHandle将此伪句柄转换为一个真正的句柄。


// 在Windows操作系统中，进程有6种优先级别（priority level/class），从低到高分别为：
// 空闲（Idel）、低普通（Below normal）、普通（Normal）、高普通（Above normal）
// 高（High）和实时（Real time），对应的符号常量为： 
	// 符号常量							对应数值 
	// IDLE_PRIORITY_CLASS				0x00000040 
	// BELOW_NORMAL_PRIORITY_CLASS		0x00004000 
	// NORMAL_PRIORITY_CLASS			0x00000020 
	// ABOVE_NORMAL_PRIORITY_CLASS		0x00008000 
	// HIGH_PRIORITY_CLASS				0x00000080 
	// REALTIME_PRIORITY_CLASS			0x00000100 

// 可以在创建新进程时，利用其创建标志参数dwCreationFlags来设置。
// 也可以用API函数GetPriorityClass和SetPriorityClass来获取和设置指定进程的优先级： 
// DWORD GetPriorityClass( HANDLE hProcess ); 
// BOOL SetPriorityClass( HANDLE hProcess, DWORD dwPriorityClass ); 
// 例如： 
// DWORD p = GetPriorityClass( GetCurrentProcess() ); 
// SetPriorityClass( GetCurrentProcess(), IDLE_PRIORITY_CLASS );


// 等待进程返回可以调用API函数WaitForSingleObject来等待指定进程（或线程）结束后返回： 
// DWORD WINAPI WaitForSingleObject( HANDLE hHandle, DWORD dwMilliseconds ); 
// 例如：WaitForSingleObject( pi.hProcess, INFINITE ); 

// 结束进程，对控制台程序，在接受到ctrl+c或者ctrl+break信号后会结束进程
// void ExitProcess(UINT uExitCode);		// 结束当前进程

// BOOl TerminateProcess(HANDLE hProcess, UINT uExitCode);	// 结束指定进程
// 进程的所有线程终止后进程也会自动终止，在用户关闭系统或注销退出系统时
// 也会导致进程终止。在结束进程后，还有调用API的CloseHandle()函数来删除
// 进程和线程对象
// CloseHandle(pi.hProcess);
// CloseHandle(pi.hThread);


#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// Start the child process
	BOOL bSucceed = CreateProcess(
		_T("D:\\vs2010_projects\\0524-1\\Debug\\0516Caret.exe"),		// 可执行文件路径或文件名
		NULL,	// 命令行参数
		NULL,	// 进程安全属性
		NULL,	// 主线程的安全属性
		FALSE,	// 是否继承父进程句柄
		0,		// 创建标志，0表示立即执行
		NULL,	// 使用父进程的环境变量
		NULL,	// 使用父进程的当前目录
		&si,	// 指向设置进程主窗口或控制条的各种属性的结构指针
		&pi		// 指向返回进程信息的结构指针
		);

	if(bSucceed == FALSE)
	{
		printf("CreateProcess failed(%d)\n", GetLastError());
		return 1;
	}

	// Wait until child porcess exits.
	WaitForSingleObject(pi.hProcess, INFINITE);

	// Close process and thread handles	关闭进程和主线程句柄
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	getchar();
	return 0;
}