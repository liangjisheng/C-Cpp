
// 原子类型允许原子访问，这意味着不需要额外的同步机制就可以执行并发的读写
// 操作。没有原子操作，递增一个变量就不是线程安全的，因为编译器首先将值
// 从内存加载到寄存器中，递增他，再把结果保存会内存，另一个线程可能在递增
// 操作的执行过程中接触到该内存，导致一个竞争条件。

#include <iostream>
#include <atomic>		// 原子操作
#include <ratio>		// 有理数
#include <chrono>		// 时间
#include <thread>
#include <vector>


using std::cout;
using std::endl;
using std::thread;
using namespace std::chrono;
using std::ratio;
using std::vector;
using std::atomic;


// 未使用原子类型
void func(int& counter)
{
	for (int i = 0; i < 100; ++i)
	{
		++counter;
		// 引入一小段延迟
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}


// 原子类型
void func_atomic(atomic<int>& counter)
{
	for (int i = 0; i < 100; ++i)
	{
		// 对原子类型执行++counter操作会在一个原子事务中，
		// 加载值，递增值，并保存值，这个过程不会被打断
		++counter;
		// 延迟1毫秒
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}


int main()
{
	int counter = 0;
	vector<thread> threads;
	for (int i = 0; i < 10; ++i)
		threads.push_back(thread{ func, std::ref(counter) });

	for (auto& t : threads)
		t.join();

	// 未使用原子类型，期待的结果是1000,但执行程序的结果却不到1000，
	// 显示了线程的竞争条件，可以使用原子类型解决
	cout << "Result = " << counter << endl;


	atomic<int> counter_atomic(0);
	vector<thread> threads_atomic;
	for (int i = 0; i < 10; ++i)
		threads_atomic.push_back(thread{ func_atomic, std::ref(counter_atomic) });

	for (auto& t : threads_atomic)
		t.join();

	// 使用原子类型，期待结果为1000，实际程序执行的结果为1000
	cout << "Result_atomic = " << counter_atomic << endl;

	system("pause");
	return 0;
}