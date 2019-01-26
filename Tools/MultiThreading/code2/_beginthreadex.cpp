
// 标准C运行库在1970年被实现了，由于当时没任何一个操作系统提供对多线程的支持
// 因此编写标准C运行库的程序员根本没考虑多线程程序使用标准C运行库的情况
// 比如标准C运行库的全局变量errno。很多运行库中的函数在出错时会将错误代号
// 赋值给这个全局变量，这样可以方便调试,这样就会导致多个线程对这个变量的访问
// 不一致导致数据覆盖的问题
// 其它像strerror()、strtok()、tmpnam()、gmtime()、asctime()等函数也会遇到
// 这种由多个线程访问修改导致的数据覆盖问题

// 为了解决这个问题，Windows操作系统提供了这样的一种解决方案——每个线程都将
// 拥有自己专用的一块内存区域来供标准C运行库中所有有需要的函数使用。而且这块
// 内存区域的创建就是由C/C++运行库函数_beginthreadex()来负责的
// 而CreateThread并不拥有本线程专用的内存区域

//_beginthreadex()最终还是会调用CreateThread()来向系统申请创建线程
// _beginthreadex()函数在创建新线程时会分配并初始化一个_tiddata块
// 这个_tiddata块自然是用来存放一些需要线程独享的数据。事实上新线程运行时会首先
// 将_tiddata块与自己进一步关联起来。然后新线程调用标准C运行库函数如strtok()时
// 就会先取得_tiddata块的地址再将需要保护的数据存入_tiddata块中。这样每个线程就
// 只会访问和修改自己的数据而不会去篡改其它线程的数据了。因此，如果在代码中有
// 使用标准C运行库中的函数时，尽量使用_beginthreadex()来代替CreateThread()

#include <stdio.h>
#include <process.h>
#include <Windows.h>

unsigned int __stdcall ThreadFun(PVOID pM)
{
	printf("线程ID号为: %8d的子线程说: hello,world\n", GetCurrentThreadId());
	return 0;
}


int main()
{
	printf("创建多个子线程\n");

	const int THREAD_NUM = 5;
	HANDLE hThreads[THREAD_NUM];
	for (int i = 0; i < THREAD_NUM; ++i)
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, NULL);
	WaitForMultipleObjects(THREAD_NUM, hThreads, TRUE, INFINITE);

	getchar();
	return 0;
}