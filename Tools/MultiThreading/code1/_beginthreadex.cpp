
#include <Windows.h>
#include <iostream>
#include <process.h>		// _beginthreadex, _endthreadex

//unsigned long _beginthreadex(void *security, unsigned stack_size,
//	unsigned(__stdcall *start_address)(void*),
//	void *arglist, unsigned initflag, unsigned *thrdaddr);

// 第一个参数为安全属性，如果为NULL则为默认安全属性
// 第二个参数是用来指定堆栈的大小，如果为0，则线程堆栈大小和创建他的线程的相同，一般用0
// 第三个参数指定线程函数，第四个参数传线程函数的参数，如果多于一个，使用结构，然后传
// 结构的指针，最后一个参数是线程的标识ID

// 结束线程函数返回_Retval指定的值
// void _endthreadex(_In_ unsigned _Retval)

using std::cout;
using std::endl;


struct agrclist
{
	char *data;
	int nCount;
};


unsigned __stdcall DoTest(void *mArgclist)
{
	agrclist *pArgclist;
	pArgclist = (agrclist *)mArgclist;
	cout << pArgclist->data << endl;
	cout << pArgclist->nCount << endl;
	_endthreadex(0);
	return 0;
}


int main()
{
	char buf[128] = "test thread.";
	HANDLE hThread = NULL;
	unsigned int threadId = 0;
	agrclist magrclist, *pmagrclist;
	pmagrclist = &magrclist;
	pmagrclist->data = buf;
	pmagrclist->nCount = 1;

	hThread = (HANDLE)_beginthreadex(NULL, 0, &DoTest, pmagrclist, NULL, &threadId);
	CloseHandle(hThread);

	system("pause");
	return 0;
}