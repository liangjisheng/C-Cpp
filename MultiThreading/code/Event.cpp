// 860.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "860.h"
#include"afxmt.h"
using namespace std;
struct SortArray {
	long * data;	// 进行排序的数据指针
	int nLen;		// 进行排序的数据元素个数
};
CEvent evtTerminate;	// 事件对象，用于标识是否所有子线程都执行完毕
CEvent evtPrint;		// 标识打印事件是否已发生
static long ThreadCompleted =0;	// 完成子线程的个数

void PrintResult(long * data,int nLen,const char * SortStr)
{
	WaitForSingleObject(evtPrint.m_hObject,INFINITE); // 等待事件有信号
	int i;
	cout<<SortStr;
	for(i=0;i<nLen-1;i++) {
		cout<<data[i]<<' ';
		//Sleep(1000);
	}
	cout<<endl;
	evtPrint.SetEvent();	// 设置事件可用
}

UINT BubbleSort(LPVOID pParam) {
	long *data=((SortArray*)pParam)->data;	// 获取需要排序的数据
	int   nLen=((SortArray*)pParam)->nLen;	// 数据个数
	// sort
	int i,j;
	long swap;
	for(i=0;i<nLen-1;i++){
		for(j=0;j<nLen-i-1;j++) {
			if(data[j]>data[j+1])
				swap=data[j],data[j]=data[j+1],data[j+1]=swap;
		}
	}
	cout<<"nLen="<<nLen<<endl;
	PrintResult(data,nLen,"BubbleSort: ");
	InterlockedIncrement(&ThreadCompleted);	// 线程完成数加1
	if(ThreadCompleted ==2)
		evtTerminate.SetEvent();

	return 0;
}

UINT SelectSort(LPVOID pParam) {
	long * data=((SortArray*)pParam)->data;
	int nLen=((SortArray*)pParam)->nLen;
	long min,swap;
	int i,j,minpos;
	for(i=0;i<nLen-1;i++) {
		minpos=i;
		min=data[i];
		for(j=i+1;j<nLen;j++) {
			if(min>data[j])
				min=data[j],minpos=j;
		}
		if(minpos!=i)
			swap=data[i],data[i]=data[minpos],data[minpos]=swap;
	}
	PrintResult(data,nLen,"SelectSort:");
	InterlockedIncrement(&ThreadCompleted);	// 线程完成数加1
	if(ThreadCompleted==2)
		evtTerminate.SetEvent();	// 线程都执行完成，设置程序结束信号量

	return 0;
}

int QuickSort(long *data,int nLow,int nHigh) {
	if(nLow>=nHigh)
		return -1;

	long pivot=data[nLow];
	int nLowSaved=nLow,nHighSaved=nHigh;
	while(nLow<nHigh) {
		while(data[nHigh]>=pivot && nHigh>nLow)
			nHigh--;
		data[nLow]=data[nHigh];
		while(data[nLow]<pivot && nLow<nHigh)
			nLow++;
		data[nHigh]=data[nLow];
	}
	data[nLow]=pivot;

	QuickSort(data,nLowSaved,nHigh-1);
	QuickSort(data,nLow+1,nHighSaved);

	return 0;
}

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

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

		long data[]={1,23,456,7890,12,345,6789,123,4567,89};
		int nLen=sizeof(data)/sizeof(long);
		long *data1,*data2,*data3;
		SortArray sa1,sa2;

		data1=new long[nLen];
		memcpy(data1,data,nLen*4);
		sa1.data=data1;
		sa1.nLen=nLen;

		data2=new long[nLen];
		memcpy(data2,data,nLen*4);
		sa2.data=data2;
		sa2.nLen=nLen;

		data3=new long[nLen];
		memcpy(data3,data,nLen*4);

		evtTerminate.ResetEvent();	// 设置程序结束事件无信号
		evtPrint.SetEvent();		// 设置打印事件有信号

		AfxBeginThread(BubbleSort,&sa1,0,0,0,NULL);	// 创建并启用冒泡排序线程
		AfxBeginThread(SelectSort,&sa2,0,0,0,NULL);
		QuickSort(data3,0,nLen-1);
		PrintResult(data2,nLen,"QuickSort: ");
		WaitForSingleObject(evtTerminate,INFINITE);	// 等待所有子线程结束

		delete []data1;
		delete []data2;
		delete []data3;
	}

	return nRetCode;
}