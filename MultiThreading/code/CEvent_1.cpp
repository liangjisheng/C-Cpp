CEvent eventWriteD;
char g_Array[10];

UINT WriteW(LPVOID pParam)
{
	CEdit * pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	for(int i=0;i<10;i++) {
		g_Array[i]='W';
		pEdit->SetWindowText(g_Array);
		Sleep(100);
	}
	eventWriteD.SetEvent();	// 设置为有信号

	return 0;
}

UINT WriteD(LPVOID pParam)
{
	CEdit * pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	WaitForSingleObject(eventWriteD.m_hObject,INFINITE);
	for(int i=0;i<10;i++) {
		g_Array[i]='D';
		pEdit->SetWindowText(g_Array);
		Sleep(100);
	}
	return 0;
}

void CMy1093Dlg::OnWritew() 
{
	// TODO: Add your control notification handler code here
	CWinThread * pWriteW=AfxBeginThread(WriteW,&m_ctrlW,
		THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pWriteW->ResumeThread();

	CWinThread * pWriteD=AfxBeginThread(WriteD,&m_ctrlD,
		THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pWriteD->ResumeThread();
}