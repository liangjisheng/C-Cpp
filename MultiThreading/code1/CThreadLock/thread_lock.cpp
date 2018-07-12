
#include "thread_lock.h"
#include <assert.h>

CThreadLockHandle::CThreadLockHandle(CThreadLock *pThreadLock, bool bAutoLock /* = true */)
{
	assert(pThreadLock != NULL);
	m_nLockCount = 0;
	m_pThreadLock = pThreadLock;
	if (bAutoLock) Lock();
	return ;
}

CThreadLockHandle::~CThreadLockHandle()
{
	while (m_nLockCount > 0)
		UnLock();
}

void CThreadLockHandle::Lock()
{
	assert(m_nLockCount >= 0);
	assert(m_pThreadLock != NULL);

	// 锁定对象
	m_nLockCount++;
	m_pThreadLock->Lock();
}

void CThreadLockHandle::UnLock()
{
	assert(m_nLockCount >= 0);
	assert(m_pThreadLock != NULL);

	// 解除锁定
	m_nLockCount--;
	m_pThreadLock->UnLock();
}