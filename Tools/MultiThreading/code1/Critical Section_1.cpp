
// 临界区(Critical Section)是一段供线程独占式访问的代码，也就是说若有一线程正在
// 访问该代码段，其它线程想要访问，只能等待当前线程离开该代码段方可进入，这样保
// 证了线程安全。临界区工作于用户级(相对于内核级)，在Window系统中CRITICAL_SECTION
// 实现临界区相关机制

// EnterCriticalSection和LeaveCriticalSection跟new/delete一样是成对调用的，
// 很多时候在调用EnterCriticalSection以后不得不在多处加入LeaveCriticalSection，
// 因为临界区内有return,break,continue,goto等等跳转，一不小心就会造成死锁。
// 基于这个原因，在很多开源代码中都对CRITICAL_SECTION进行了封装。
// 下面是我从某开源库中摘取的封装后的代码：

#include <Windows.h>

class Mutex
{
public:
	Mutex()				{ InitializeCriticalSection(&section); }
	~Mutex()			{ DeleteCriticalSection(&section); }
	void Enter()		{ EnterCriticalSection(&section); }
	void Leave()		{ LeaveCriticalSection(&section); }
	
	struct Lock;
protected:
	Mutex(const Mutex&);
	Mutex& operator=(const Mutex&);

	CRITICAL_SECTION section;
};


struct Mutex::Lock
{
	Mutex& s;
	Lock(Mutex& src) : s(src)	{ s.Enter(); }
	~Lock()	{ s.Leave(); }
};


// 使用示例
class A
{
public:
	void Foo();
private:
	Mutex mutex;
};


void A::Foo()
{
	Mutex::Lock lock(mutex);
	// 临界区代码
}


