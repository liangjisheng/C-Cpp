#ifndef __THREAD_LOCK_H__
#define __THREAD_LOCK_H__

#include <Windows.h>

// 经过这个类的封装，使用临界区实现线程同步只需要2步：
// 1.初始化一个全局的 CThreadLock 对象，为后面调用做准备。
// 2.每当需要使用临界区时，在作用域中声明一个局部变量：CThreadLockHandle
//   当其生存周期结束时，将自动释放临界区资源

// 临界区同步类
class CThreadLock
{
private:
	CRITICAL_SECTION m_csLock;		// 临界区变量

public:
	inline CThreadLock() { ::InitializeCriticalSection(&m_csLock); }
	inline ~CThreadLock() { ::DeleteCriticalSection(&m_csLock); }

public:
	inline void Lock() { ::EnterCriticalSection(&m_csLock); }
	inline void UnLock() { ::LeaveCriticalSection(&m_csLock); }
};

// 安全同步锁句柄
class CThreadLockHandle
{
private:
	int m_nLockCount;			// 锁定计数
	CThreadLock *m_pThreadLock;	// 锁定对象

public:
	CThreadLockHandle(CThreadLock *pThreadLock, bool bAutoLock = true);
	virtual ~CThreadLockHandle();

public:
	void Lock();
	void UnLock();
	// 获取锁定次数
	int inline GetLockCount() { return m_nLockCount; }
};

#endif  //__THREAD_LOCK_H__