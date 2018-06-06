
// 可以在线程中指定要执行的类的成员函数

#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class Request
{
public:
	Request(int id) : mId(id) {}
	void process()
	{
		cout << "Processing request " << mId << endl;
	}

private:
	int mId;
};


int main()
{
	Request req(100);
	thread t{ &Request::process, &req };
	t.join();

	// 通过这种技术，可在不同线程中执行某个对象中的方法，如果有其它线程
	// 访问同一个对象，需要确认这种访问是线程安全的，需要加上同步

	system("pause");
	return 0;
}

