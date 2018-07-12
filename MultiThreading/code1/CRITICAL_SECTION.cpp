
CRITICAL_SECTION g_cs;
char g_cArr[10];

UINT ThreadProc_a(LPVOID pParam)
{
	EnterCriticalSection(&g_cs);
	// 对共享资源进行写操作
	for(int i = 0; i < 10; i++)
	{
		g_cArr[i] = 'a';
		Sleep(1);
	}
	LeaveCriticalSection(&g_cs);
	return 0;
}


UINT ThreadProc_b(LPVOID pParam)
{
	EnterCriticalSection(&g_cs);
	for(int i = 0; i < 10; i++)
	{
		g_cArr[i] = 'b';
		Sleep(1);
	}
	LeaveCriticalSection(&g_cs);
	return 0;
}


InitializeCriticalSection(&g_cs);
AfxBeginThread(ThreadProc_a, NULL);
AfxBeginThread(ThreadProc_b, NULL);
AfxBeginThread(ThreadProc_a, NULL);

Sleep(300);				// 等待计算完毕
for(int i = 0; i < 10; i++)
	cout << g_cArr[i];
cout << endl;

system("pause");

