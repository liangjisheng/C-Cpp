#include"stdafx.h"
#include"memory"	// 定义share_ptr
#include"iostream"
#include"tchar.h"
using namespace std;

int _tmain(int argc,_TCHAR* argv[])
{
	shared_ptr<int> pFirst(new int);
	// 这时，只有pFirst这个指针指向这块int类型的内存
	// 所以这时的引用计数是1
	cout<<"当前引用计数是:"<<pFirst.use_count()<<endl;
	{
		// 创建另外一个share_ptr,并用pFirst对其进行赋值，
		// 让它们指向同一块内存资源
		shared_ptr<int> pCopy=pFirst;
		// 两个指针同时指向一块内存资源，所以这一资源的引用计数增加为2
		cout<<"当前引用计数:"<<pFirst.use_count()<<endl;
	}
	// 超出pCopy的可见域，pCopy结束其生命周期，引用计数减1
	cout<<"当前引用计数:"<<pFirst.use_count()<<endl;

	system("pause");
	// 当程序最终结束执行返回，pFirst指针也结束其生命周期后，
	// 没有任何指针指向内存资源，引用计数为0，内存资源自动释放
	cout<<"当前引用计数:"<<pFirst.use_count()<<endl;
	return 0;
}
