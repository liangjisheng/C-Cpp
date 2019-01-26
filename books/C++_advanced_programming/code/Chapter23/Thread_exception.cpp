
// C++�е��쳣���ƽ����ڵ��̵߳������ÿ���̶߳������׳��Լ����쳣����
// ���Ǳ������Լ����߳��ڲ�׽�쳣��һ���߳��׳����쳣��������һ���߳�
// �в��񡣲�ʹ�ñ�׼�⣬�ͺ������̼߳������ش����쳣

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


// һ�������쳣����ͨ��current_exception()����������ڴ����쳣������
// Ȼ��������ø���exception_ptr������֮���߳������˳�
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
	// ���error��������쳣�����ڵ�ǰ�߳��������׳��쳣
	// �쳣�ʹ�һ���߳�ת�Ƶ���һ���̡߳�
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
