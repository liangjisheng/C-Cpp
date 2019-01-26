CCriticalSection critical_section;
char g_Array[10];

UINT WriteW(LPVOID pParam)
{
	CEdit * pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	// 锁定临界区
	critical_section.Lock();
	for(int i=0;i<10;i++) {
		g_Array[i]='W';
		pEdit->SetWindowText(g_Array);
		Sleep(100);
	}
	critical_section.Unlock();
	return 0;
}

UINT WriteD(LPVOID pParam)
{
	CEdit * pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	// 锁定临界区
	critical_section.Lock();
	for(int i=0;i<10;i++) {
		g_Array[i]='D';
		pEdit->SetWindowText(g_Array);
		Sleep(100);
	}
	critical_section.Unlock();
	return 0;
}

void CMy1092Dlg::OnWritew() 
{
	// TODO: Add your control notification handler code here
	CWinThread* pWriteW=AfxBeginThread(WriteW,&m_ctrlW,
		THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pWriteW->ResumeThread();
}


void CMy1092Dlg::OnWrited() 
{
	// TODO: Add your control notification handler code here
	CWinThread* pWriteD=AfxBeginThread(WriteD,&m_ctrlD,
		THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pWriteD->ResumeThread();
}