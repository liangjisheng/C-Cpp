
#ifndef PROGRESS_THREAD_H_
#define PROGRESS_THREAD_H_

#include <process.h>
#include <Windows.h>

#define WM_USER_MSG WM_USER + 1001

class CThread
{
public:
	// 线程回调函数必须是全局函数，类的静态函数可以作为线程回调函数
	static void Run(void *ptr);
public:
	CThread(void);
	~CThread(void);
};


#endif