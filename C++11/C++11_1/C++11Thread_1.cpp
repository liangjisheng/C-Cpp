
// 函数对象作为某个线程的线程函数
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class Counter
{
public:
	Counter(int id, int numIterations) 
		: mId(id), mNumIterations(numIterations)
	{}

	void operator()() const
	{
		for (int i = 0; i < mNumIterations; ++i)
		{
			cout << "Coutner " << mId << " has value ";
			cout << i << endl;
		}
	}

private:
	int mId;
	int mNumIterations;
};


class Counter1
{
public:
	Counter1() {}
	void operator()()
	{
		for (int i = 0; i < 10; ++i)
			cout << i << endl;
	}
};


// main里演示了通过函数对象初始化线程的3中方法，
// 函数对象总是复制到线程的某个内部存储中。如果要在函数对象的某个特定实例
// 上执行operator()而非进行复制，那么应该使用<functional>头文件中的
// std::ref()通过引用传入该实例
int main()
{
	// Using uniform initialization syntax
	thread t1{ Counter{1, 20} };
	// Using named variable
	Counter c(2, 12);
	thread t2(c);
	// Using temporary object
	thread t3(Counter(3, 10));

	// 如果使用圆括号而不是使用统一初始化列表，则编译器会将下面这一行
	// 解释为t4函数的声明，返回一个thread对象，其参数是一个指针，它指向
	// 返回一个Counter1对象的无参函数，因此建议使用统一初始化语法，如果
	// 编译器不支持统一初始化语法，必须添加额外的圆括号，以防止编译器
	// 将代码解释为函数声明 thread t4((Counter1())); 为正确的声明一个
	// 线程对象
	thread t4((Counter1()));

	// Wait for threads to finish
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	system("pause");
	return 0;
}

