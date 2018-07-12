
//VC++中本身就有内存泄漏检查的机制,你可以在向导生成的支持MFC的工程中看到如下代码:
//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

// 通过它们,你能非常容易的发现代码中的内存泄漏,但是如果手工将这个功能移植到非MFC
// 工程中去是很繁琐的一件事,另外它还有一个bug,在多线程并发调用这个DEBUG_NEW时会
// 导致系统级错误,因此本人在此重写了这个功能,将以下的debug_new.h和debug_new.cpp
// 添加到工程中,并在需要检测的cpp中#include "debug_new.h"和main中一开始处加入REG_DEBUG_NEW宏即可.

/**
 * 此文件与debug_new.cpp配合使用，用于在调试期间发现内存泄露
 * 仅在VC++编译器中适用(包括Intel C++,因为它适用了相同的库)
*/

#ifndef _DEBUG_NEW_H
#define _DEBUG_NEW_H

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#undef new
extern void _RegDebugNew(void);
extern void* _cdecl operator new(size_t, const char*, int);
extern void _cdecl operator delete(void*, const char*, int);
#define new new(__FILE__, __LINE__)
#define REG_DEBUG_NEW _RegDebugNew();
#else
#define REG_DEBUG_NEW
#endif // _DEBUG

#endif // _DEBUG_NEW_H
