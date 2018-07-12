// 表示还能否在继续创建线程
volatile BOOL g_bRunFlag = true;

DWORD WINAPI ThreadFunc(LPVOID threadNum)
{
	while (g_bRunFlag)
		Sleep(1000);
	return 0;
}

void CMy1081Dlg::OnTest() 
{
	DWORD ThreadID;
	GetDlgItem(IDC_TEST)->EnableWindow(false);
	long nCount=0;
	while(g_bRunFlag)
	{
		if(CreateThread(NULL,0,ThreadFunc,NULL,0,&ThreadID)==NULL) 
		{
			g_bRunFlag =false;
			break;
		}
		else
			nCount++;
	}
	m_nCount=nCount;
	UpdateData(false);
	// 延时结束，等待所有创建的线程结束
	Sleep(1000);
	g_bRunFlag =true;
	GetDlgItem(IDC_TEST)->EnableWindow(true);
}
