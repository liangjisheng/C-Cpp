#include <stdio.h>
#include <windows.h>
#include <tchar.h>


void test_Handle_1()
{
	HMENU	hGlobal;
	PTSTR	pGlobal;
	TCHAR	szBuffer[] = TEXT("Test text");
	// HGLOBAL

	//GMEM_FIXED
	hGlobal = GlobalAlloc(GMEM_FIXED, (lstrlen(szBuffer)+1) * sizeof(TCHAR));
	pGlobal = GlobalLock(hGlobal);
	lstrcpy(pGlobal, szBuffer);
	_tprintf(TEXT("pGlobal and hGlobal%s\n"), 
		(pGlobal==hGlobal ? TEXT(" equal") : TEXT(" not equal")));
	GlobalUnlock(hGlobal);

	_tprintf(TEXT("use handle as pointer to access data : %s\n"), hGlobal);

	GlobalFree(hGlobal);

	//GMEM_MOVABLE
	hGlobal = GlobalAlloc(GMEM_MOVEABLE, (lstrlen(szBuffer)+1) * sizeof(TCHAR));
	pGlobal = GlobalLock(hGlobal);
	lstrcpy(pGlobal, szBuffer);
	_tprintf(TEXT("pGlobal and hGlobal%s\n"), 
		(pGlobal==hGlobal ? TEXT(" equal") : TEXT(" not equal")));
	_tprintf(TEXT("use handle as pointer to access data : %s\n"), hGlobal);
	GlobalUnlock(hGlobal);

	GlobalFree(hGlobal);
}

void test_Handle_2()
{
	int k = 0;
	int nBytes = 64;
	char szRes[64] = {0};
	int nInt = nBytes / sizeof(int);
	int nChar = nBytes / sizeof(char);
	int nDouble = nBytes / sizeof(double);
	char *pChar = NULL;
	// HGLOBAL内存句柄，指针只是指向内存中的一个点，而句柄则是封装了指针，并加入
	// 了封装指针区域的一些属性，可以把句柄理解为一段区域.
	HGLOBAL hMemHandle = GlobalAlloc(GHND, nBytes);	// 句柄,封装了nBytes个字节的内存

	// 分配的是可移动内存，所以在使用这块内存的时候需要先将这块内存锁住，使得
	// 整个内存变成固定地址内存
	int *pInt = (int *)GlobalLock(hMemHandle);		// 返回句柄封装的指针	
	for(k = 0; k < nInt; k++)	
		*(pInt + k) = k;	
	// %i表示将pInt + 4 * (nInt - 1)这个指针之后指向的4个字节的内存解释为一个整数
	sprintf(szRes, "testing: pInt[49] = %i", pInt[nInt - 1]);
	GlobalUnlock(hMemHandle);
	printf("%s\n", szRes);
	memset(szRes, 0, nBytes);

	pChar = (char *)GlobalLock(hMemHandle);
	for(k = 0; k < nBytes - 1; k++)
		*(pChar + k) = 'a';
	*(pChar + k) = '\0';
	memcpy(szRes, pChar, nBytes);
	GlobalUnlock(hMemHandle);
	printf("%s\n", szRes);

	GlobalFree(hMemHandle);
}


// 句柄是一个标识符，是拿来标识对象或者项目的。	句柄类似指向指针的指针
// 仅仅是类似，通过句柄可以找到对应的数据，但是不是二级指针。我们知道
// 所谓指针是一种内存地址。应用程序启动后，组成这个程序的各对象是驻留在
// 内存中的。简单地理解，似乎我们只要获知这个内存的首地址，就可以随时用
// 这个地址访问对象了。如果您真的这样认为，那您可就大错特错了。Windows是
// 一个以虚拟内存为基础的操作系统。在这种系统环境下，Windows内存管理器经
// 常在内存中来回移动对象，以此来满足各种应用程序的内存需要。对象被移动
// 意味着它的地址变化了。如果地址总是如此变化，我们该到哪里去找那一个对象呢

// 为了解决这个问题，Windows操作系统为全体应用程序腾出一些内存单元，用来专
// 门登记各应用程序的对象在内存中的地址的变化，而前者的物理地址在系统运行
// 期间是始终保持不变的。Windows内存管理器移动了对象在内存中的位置后，会把
// 该对象新的地址及时地告知给对应的句柄进行更新。这样我们只要知道这个句柄
// 就可以间接地知道对象具体在内存中的哪个位置了。这个地址是在对象装载(Load)
// 时由系统分配给的，当对象卸载时(Unload)又释放给系统

// 内核对象句柄，是用来标识某个内核对象的一个ID　同一个对象的该id对于每个进程
// 是不同的，具体如何实现是ms不公开的算法，以下是一个近似的，可能的算法：
// 进程创建时，windows系统为进程构造了一个句柄表
// 当该进程希望获得一个内核对象句柄或者创建一个内核对象从而获得该对象句柄时
// 系统会将在句柄表中增加一个表项，表项的内容中存储了指向目标内核对象的指针
// 同时，系统返回这个表项在句柄表中的索引作为句柄。


int main(int argc, char *argv[])
{
	test_Handle_2();

	getchar();
	return 0;
}

