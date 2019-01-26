DWORD _stdcall ThreadProc(LPVOID lpParameter)
{
	COperateThreadDlg* pDlg = (COperateThreadDlg*)lpParameter;
	pDlg->m_Prog.SetRange32(0, 99999);
	for (int i = 0; i < 99999; i++)
		pDlg->m_Prog.SetPos(i);
	return 0;
}

void COperateThreadDlg::OnButtonCreate() 
{
	// 返回线程句柄
	m_hThread = CreateThread(NULL,0,ThreadProc,this,0,NULL);
}

void COperateThreadDlg::OnButtonSuspend() 
{
	// DWORD SuspendThread(HANDLE hThread);
	// 成功返回之前的挂起数，失败返回0xFFFFFFFF
	SuspendThread(m_hThread);	
}

void COperateThreadDlg::OnButtonResume() 
{
	// DWORD ResumeThread(HANDLE hThread);
	// 成功返回之前挂起的线程次数,失败返回0xFFFFFFFF
	// 要使线程在挂起之后可以继续运行，
	// 则唤醒的次数与挂起的次数是相同的
	ResumeThread(m_hThread);
}

void COperateThreadDlg::OnButtonTerminate() 
{
	// BOOL TerminateThread(HANDLE hThread,DWORD dwExitCode);
	TerminateThread(m_hThread,0);
}