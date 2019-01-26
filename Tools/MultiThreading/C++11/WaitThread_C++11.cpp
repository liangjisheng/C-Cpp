
/***********************************************************
 * @name: WaitThread_C++11.cpp
 * @brief: C++11等待线程结束
 * @author: 梁基圣
 * @date: 2018/7/22 12:20:22
 * @version: 1.0
 **********************************************************/

// 一旦我们开启了新线程后，就需要决定是要等待这个线程结束还是将其设置为分离状态
// （自行运行，与父线程没什么关系了）。如果不等待线程运行结束的话，有一个问题我们
// 需要注意：必须确保该线程结束前访问到的数据都是有效的，
// 否则会引发异常或输出一些预料之外的结果。

#include <iostream>
#include <thread>

using namespace std;

void do_something(int i) { cout << "i = " << i << endl; }

struct func
{
	int& i;
	func(int& i_) : i(i_) {}
	void operator()()
	{
		for (unsigned j = 0; j < 1000000; ++j)
			do_something(i);
	}
};

void oops()
{
	int some_local_state = 8;
	func my_func(some_local_state);
	thread my_thread(my_func);
	my_thread.detach();		// 将线程设置为分离状态
}

int main()
{
	// func类对象引用了oops函数的some_local_state这个局部变量，当oops函数退出的时候，
	// 局部变量会自动销毁，此时线程仍然继续运行，则访问到的some_local_state是一个
	// 销毁的变量，会输出我们意想不到的结果
	oops();

	// 这句话输出后，主线程就结束了，子线程也随之结束
	//cout << "Hello World" << endl;

	// 这句话会使得主线程暂停下来，要求用户输入，主线程并没有结束，所以子线程会一直运行
	//system("pause");

	return 0;
}
