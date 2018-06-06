
// CreateThread(), _beginthread(),都要求线程函数只有一个参数，
// 另一方面,标准C++的std::thread类使用的函数可以有任意数量的参数
// thread类的构造函数是一个可变参数模板， 可以接受任意数量的参数


#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void counter(int id, int numIterations);

int main()
{
	// 启动两个线程，执行counter()函数，线程启动后，调用两个线程的join().
	// 这是为了确保主线程一直运行，直到两个线程都完毕。调用t1.join()会
	// 阻塞，直到线程t1结束执行。调用t2.join()会阻塞，直到线程t2结束执行。
	// 如果没有这两个join()的调用，main()函数在加载完这两个线程之后会立即
	// 结束执行。这会导致应用程序关闭：应用程序启动的其它线程也都终止，
	// 不论这些线程是否结束执行

	// 在这些小例子中，这些join()调用时必要的，在真实世界的应用程序中，
	// 应该避免使用join()，因为这会导致调用join()的线程阻塞。通常有更好
	// 的方法，例如在GUI应用程序中，一个线程完成后，可以向UI线程发布消息。
	// UI线程本身有个消息循环处理消息，例如鼠标移动和点击按钮等，这个消息
	// 循环也可以从线程接受消息，并作出需要的响应，这些都不需要通过join()
	// 调用来阻塞UI线程

	// 不同的系统上的输出会有所不同，很可能每次运行的结果都不同，因为两个
	// 线程同时执行counter()函数，所以输出取决于系统中处理核心的数量以及
	// 操作系统的线程调度

	// 不管下面的参数为false还是true，都会造成两个线程访问cout的冲突
	// cout.sync_with_stdio(false);
	// cout.sync_with_stdio(true);

	// 线程函数的参数总是复制到线程的某个内部存储中。
	// 通过<functional>头文件中的std::ref()按引用传递参数
	thread t1(counter, 1, 6);
	// 如果在这里调用t1.join()会造成t1的阻塞，导致下面的线程启动不了
	// 只有在t1线程返回之后，t2线程才启动
	// t1.join();

	thread t2(counter, 2, 4);	
	t1.join();
	t2.join();

	system("pause");
	return 0;
}


void counter(int id, int numIterations)
{
	for (int i = 0; i < numIterations; ++i)
	{
		cout << "Counter " << id << " has value ";
		cout << i << endl;
	}
}

