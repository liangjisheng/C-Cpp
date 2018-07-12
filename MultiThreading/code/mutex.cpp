// 859.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "859.h"
#include"afxmt.h"
CCriticalSection section;	// 临界区对象
CMutex mutex;				// 互斥量对象
int data[10];

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

UINT ThreadProc1(LPVOID pParam) {
	CSingleLock sgLock(&mutex);		// 声明一个CSingleLock对象
	sgLock.Lock();
	for(int i=0;i<10;i++) {
		data[i]=i*1;
		if(i==3) Sleep(1000);
	}
	sgLock.Unlock();
	return 0;
}

UINT ThreadProc2(LPVOID pParam) {
	CSingleLock sgLock(&mutex);		// 声明一个CSingleLock对象
	sgLock.Lock();
	for(int i=0;i<10;i++) {
		data[i]=i*11;
		if(i==5) Sleep(1000);
	}
	sgLock.Unlock();
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		//CString strHello;
		//strHello.LoadString(IDS_HELLO);
		//cout << (LPCTSTR)strHello << endl;

		AfxBeginThread(ThreadProc1,NULL,0,0,0,NULL);	// 创建并启用线程1
		AfxBeginThread(ThreadProc2,NULL,0,0,0,NULL);
		Sleep(1000);
		for(int i=0;i<10;i++)
			cout<<data[i]<<' ';
		cout<<endl;
	}

	return nRetCode;
}


