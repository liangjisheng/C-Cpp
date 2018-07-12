
#include <iostream>
#include "mempool.h"

using namespace std;

class ActualClass
{
	static int count;
	int num[10];
public:
	ActualClass()
	{
		count++;
		for(int i = 0; i < 10; i++)
			num[i] = count + i;
	}
	void show()
	{
		cout << this << ":";
		for(int i = 0; i < 10; i++)
			cout << num[i] << " ";
		cout << endl;
	}
	void* operator new(size_t size);
	void operator delete(void *p);
};

class theMemoryPool
{
	// 针对类ActualClass实例化的一个内存池，每个内存块容纳两个ActualClass对象
	static MemPool<sizeof(ActualClass), 2> mp;		// 此处仅仅是声明
	friend class ActualClass;
};

void* ActualClass::operator new(size_t size)
{
	return theMemoryPool::mp.malloc();
}

void ActualClass::operator delete(void *p)
{
	theMemoryPool::mp.free(p);
}

MemPool<sizeof(ActualClass), 2> theMemoryPool::mp;		// 此处应该是定义

int ActualClass::count;


int main()
{
	ActualClass *p1 = new ActualClass;
	p1->show();
	ActualClass *p2 = new ActualClass;
	p2->show();
	delete p1;
	
	p1 = new ActualClass;
	p1->show();
	ActualClass *p3 = new ActualClass;
	p3->show();
	
	/*delete p1;
	delete p2;
	delete p3;
	p1 = NULL;
	p2 = NULL;
	p3 = NULL;*/

	system("pause");
	return 0;
}

