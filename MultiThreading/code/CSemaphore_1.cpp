// 资源最多访问线程2个，当前可访问线程2个
CSemaphore semaphoreWrite(2, 2);
char g_Array[10];

UINT WriteA(LPVOID pParam)
{
	CEdit * pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	WaitForSingleObject(semaphoreWrite.m_hObject,INFINITE);
	CString str;
	for(int i=0;i<10;i++) {
		pEdit->GetWindowText(str);
		g_Array[i]='A';
		str+=g_Array[i];
		pEdit->SetWindowText(str);
		Sleep(100);
	}
	ReleaseSemaphore(semaphoreWrite.m_hObject,1,NULL);
	return 0;
}

UINT WriteB(LPVOID pParam)
{
	CEdit * pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	WaitForSingleObject(semaphoreWrite.m_hObject,INFINITE);
	CString str;
	for(int i=0;i<10;i++) {
		pEdit->GetWindowText(str);
		g_Array[i]='B';
		str+=g_Array[i];
		pEdit->SetWindowText(str);
		Sleep(100);
	}
	ReleaseSemaphore(semaphoreWrite.m_hObject,1,NULL);
	return 0;
}

UINT WriteC(LPVOID pParam)
{
	CEdit * pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	WaitForSingleObject(semaphoreWrite.m_hObject,INFINITE);
	CString str;
	for(int i=0;i<10;i++) {
		// pEdit->GetWindowText(str);
		g_Array[i]='C';
		// str+=g_Array[i];
		pEdit->SetWindowText(g_Array);
		Sleep(100);
	}
	ReleaseSemaphore(semaphoreWrite.m_hObject,1,NULL);
	return 0;
}

void CMy1094Dlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	CWinThread * pWriteA=AfxBeginThread(WriteA,&m_ctrlA,
		THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pWriteA->ResumeThread();

	CWinThread * pWriteB=AfxBeginThread(WriteB,&m_ctrlB,
		THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pWriteB->ResumeThread();

	CWinThread * pWriteC=AfxBeginThread(WriteC,&m_ctrlC,
		THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pWriteC->ResumeThread();
}