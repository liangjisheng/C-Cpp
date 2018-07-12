
// _CrtDumpMemoryLeaks()就是检测从程序开始到执行该函数进程的堆使用情况，
// 通过使用_CrtDumpMemoryLeaks()我们可以进行简单的内存泄露检测。
// 检测内存泄漏的主要工具是调试器和 C 运行时库 (CRT) 调试堆函数
// 若要启用调试堆函数，请在程序中包括以下语句：

#define _CRTDBG_MAP_ALLOC  

#include <stdlib.h>  

#include <crtdbg.h>  

// #include必须按照以上所示顺序。如果更改了顺序，所使用的函数可能无法使用。

// 通过包括crtdbg.h，将 malloc 和 free 函数映射到其“Debug”版本 
// _malloc_dbg 和 _free_dbg，这些函数将跟踪内存分配和释放。
// 此映射只在调试版本（在其中定义了_DEBUG）中发生。发布版本使用普通的
// malloc 和 free 函数。

// 注意：在编译时要把工程属性中的“代码生成”中的“运行时库”改为：
// “多线程调试（/MTd)”，否则编译报错

#ifdef _DEBUG
#define new  new(_CLIENT_BLOCK, __FILE__, __LINE__)  
#endif

#include <stdio.h>
// #include <string.h>				// for memset
#include <memory.h>					// for memset


// on_off为true打印内存泄露，为false则不打印
void detect_memory_leaks(bool on_off)
{
	int flags = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	if(!on_off)
		flags &= ~_CRTDBG_LEAK_CHECK_DF;
	else
	{
		flags |= _CRTDBG_LEAK_CHECK_DF;
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	}

	_CrtSetDbgFlag(flags);
}


// (51)代表第51次内存分配操作发生了内存泄露，在这个例子中，只显示分配了一次内存
// 前50次的内存分配是在初始化的时候调用的，51表示内存分配序号
//Detected memory leaks!
	//Dumping objects ->
//d:\vs2010_projects\0810-5\0810-5\memory_leak.cpp(51) : {60} client block at 0x003733B0, subtype 0, 40 bytes long.
//Data: <                > 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
	//  Object dump complete.


inline void EnableMemLeakCheck()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

int main()  
{
	//detect_memory_leaks(true);

	EnableMemLeakCheck();
	int* leak = new int[10];
	memset(leak, 0, sizeof(int) * 10);

	// 让程序运行到底68次分配内存的时候，自动停下来，进入调试状态
	_CrtSetBreakAlloc(68);

	// 确定自程序开始执行以来是否发生过内存泄漏，如果发生过，
	// 则转储所有已分配对象。如果已使用 _CrtSetDumpClient 
	// 安装了挂钩函数，那么，_CrtDumpMemoryLeaks每次转储 
	// _CLIENT_BLOCK 块时，都会调用应用程序所提供的挂钩函数。
	// CrtDumpMemoryLeaks()就是显示当前的内存泄漏。 注意是“当前”
	// 也就是说当它执行时，所有未销毁的对象均会报内存泄漏。
	// 因此尽量让这条语句在程序的最后执行。
	// 它所反映的是检测到泄漏的地方。
	//_CrtDumpMemoryLeaks();  

	system("pause");  
	return 0;  

}  