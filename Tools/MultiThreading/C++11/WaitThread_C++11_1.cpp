
/***********************************************************
 * @name: WaitThread_C++11_1.cpp
 * @brief: 等待线程结束C++11
 * @author: 梁基圣
 * @date: 2018/7/22 12:35:32
 * @version: 1.0
 **********************************************************/

// 调用join函数等待线程结束。在启动新线程之后且在调用join函数之前，
// 如果有异常的出现，则很可能会跳过join()的调用。为避免应用程序可能
// 因抛出的异常而终止的情况，下边提供一些解决这样问题的方案
// 在上个程序的基础上，使用简单的try...catch...异常捕获机制

#include <iostream>
#include <thread>

using namespace std;

void do_something(int i) { cout << "i = " << i << endl; }

void do_something_in_current_thread()
{

}

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

void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	thread t(my_func);
	try {
		do_something_in_current_thread();
	}
	catch (...)
	{
		t.join();	// execute this when has exception
		throw;
	}
	t.join();		// execute this when has no exception
}


int main()
{
	f();
	cout << "Hello World" << endl;

	return 0;
}
