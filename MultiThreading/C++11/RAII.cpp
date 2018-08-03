
/***********************************************************
 * @name: RAII.cpp
 * @brief: C++ RAII技术处理
 * @author: 梁基圣
 * @date: 2018/7/22 12:49:07
 * @version: 1.0
 **********************************************************/

// RAII技术：我们在C++中经常使用new申请了内存空间，但是却也经常
// 忘记delete回收申请的空间，容易造成内存溢出，于是RAII技术就诞生了，
// 来解决这样的问题。RAII（Resource Acquisition Is Initialization）
// 机制是Bjarne Stroustrup首先提出的，是一种利用对象生命周期来控制程序资源
// （如内存、文件句柄、网络连接、互斥量等等）的简单技术

#include <iostream>
#include <thread>

using namespace std;

void do_something(int i) { cout << "i = " << i << endl; }

void do_something_in_current_thread() {}

struct func
{
	int& i;
	func(int& i_) : i(i_) {}
	void operator()()
	{
		for (unsigned j = 0; j < 10; ++j)
			do_something(i);
	}
};

class thread_guard
{
	thread& t;
public:
	explicit thread_guard(thread& t_) : t(t_) {}
	~thread_guard()
	{
		// tests to see if the std::thread object is joinable()
		// because join() can be called only once for a given thread of execution
		if (t.joinable())
			t.join();
	}

	// 禁止编译器自动生成拷贝构造和拷贝赋值函数
	thread_guard(thread_guard const&) = delete;
	thread_guard& operator=(thread_guard const&) = delete;
};

void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	thread t(my_func);
	thread_guard g(t);
}


int main()
{
	f();
	cout << "Hello World" << endl;

	return 0;
}
