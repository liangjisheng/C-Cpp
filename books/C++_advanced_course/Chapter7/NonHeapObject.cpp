
// 有时，程序员可能不希望对象在堆上产生，比如某类由于封装了其它的资源，因此它的
// 析构函数的调用就显得非常重要，如果该对象只能在栈中产生，这样就能在异常的情况
// 下自动释放封装的资源，而如果对象被允许在堆上产生，那么对象的析构函数不能被正
// 常调用的可能性会增大
// 产生堆对象的唯一方法是使用new操作，分为2步，第一步调用operator new,第二步是
// 调用构造函数，而operator new是可以重载的，所以可以使operator new变为private

#include <stdlib.h>

class Resource {};		// 代表被封装的资源类

class NonHeapObject
{
private:
	Resource *ptr;		// 指向被封装的资源
	void* operator new(size_t size)
	{ return malloc(size); }		// 非严格实现，仅作示意
	void operator delete(void *pp)
	{ free(pp); }					// 非严格实现，仅作示意
public:
	NonHeapObject()
	{
		// 此处可以获得需要封装的资源，让ptr指向该资源
		ptr = new Resource();
	}
	~NonHeapObject() { delete ptr; }	// 释放资源
};

// NonHeapObject现在就是一个禁止产生堆对象的类了

int main()
{
	// error,因为将operator new变成私有的
	// NonHeapObject *np = new NonHeapObject();
	// delete np;

	// 这种禁止产生堆对象的方法只是提醒程序员不要在堆上产生某类的对象，如果程序员
	// 想强行在堆上创建对象，一样可以通过别的途径实现，比如先在堆上申请一块空间，
	// 然后利用定位放置new(placement new)操作产生对象，或者手工创建一个对象等等

	system("pause");
	return 0;
}