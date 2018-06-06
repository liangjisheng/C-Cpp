
// C++中的异常机制仅限于单线程的情况。每个线程都可以抛出自己的异常，但
// 他们必须在自己的线程内捕捉异常。一个线程抛出的异常不能在另一个线程
// 中捕获。不使用标准库，就很难在线程键正常地处理异常

#include <iostream>
#include <thread>
#include <stdexcept>

using std::cout;
using std::endl;
using std::thread;
using std::runtime_error;
using std::exception_ptr;
using std::current_exception;
using std::exception;


void doSomeWork()
{
	for (int i = 0; i < 5; ++i)
		cout << i << endl;

	cout << "Thread throwing a runtime_error exception..." << endl;
	throw runtime_error("Execption from thread");
}


// 一旦捕获异常，就通过current_exception()函数获得正在处理异常的引用
// 然后将这个引用赋给exception_ptr参数，之后，线程正常退出
void threadFunc(exception_ptr& err)
{
	try {
		doSomeWork();
	}
	catch (...)
	{
		cout << "Thread caught exception, return exception..." << endl;
		err = current_exception();
	}
}


void doWorkInThread()
{
	exception_ptr error;
	// Launch background thread
	thread t{ threadFunc, ref(error) };
	// Wait for thread to finish
	t.join();
	// See if thread has thrown any exception
	// 检查error，如果有异常，则在当前线程中重新抛出异常
	// 异常就从一个线程转移到另一个线程。
	if (error)
	{
		cout << "Main thread received exception, rethrowing it..." << endl;
		rethrow_exception(error);
	}
	else
		cout << "Main thread did not receive any exception." << endl;
}


int main()
{
	try {
		doWorkInThread();
	}
	catch (const exception& e)
	{
		cout << "Main function caught: '" << e.what() << "'" << endl;
	}

	system("pause");
	return 0;
}
