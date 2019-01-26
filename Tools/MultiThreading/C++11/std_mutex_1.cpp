
/***********************************************************
 * @name: std_mutex_1.cpp
 * @brief: mutex
 * @author: 梁基圣
 * @date: 2018/7/25 15:49:14
 * @version: 1.0
 **********************************************************/

// std::mutex不允许拷贝构造，也不允许move拷贝，最初的对象处于unlock状态
// lock()锁住互斥量，直到调用unlock()解锁之前，该线程一直拥有该锁.有3种
// 情况，(1).如果该互斥量当前没有被锁住，则调用线程将该互斥量锁住，直到调用
// unlock之前，该线程一直拥有该锁。(2).如果当前互斥量被其他线程锁住，
// 则当前的调用线程被阻塞住.(3).如果当前互斥量被当前调用线程锁住,则会产生死锁(deadlock)
// unlock(), 解锁,释放对互斥量的所有权
// try_lock(),尝试锁住互斥量,如果互斥量被其他线程占有,则当前线程也不会
// 被阻塞.线程调用该函数也会出现下面3种情况,(1).如果当前互斥量没有被其
// 他线程占有,则该线程锁住互斥量,直到该线程调用unlock释放互斥量.(2).如
// 果当前互斥量被其他线程锁住,则当前调用线程返回false,而并不会被阻塞掉.
// (3).如果当前互斥量被当前调用线程锁住,则会产生死锁(deadlock)

#include <iostream>
#include <thread>
#include <mutex>

volatile int counter(0);	// non-atomic counter
std::mutex mtx;				// locks access to counter

void attempt_10k_increases()
{
	if (mtx.try_lock())
	{
		for (int i = 0; i < 10000; ++i)
			++counter;
	}
	mtx.unlock();

	//for (int i = 0; i < 10000; ++i)
	//{
	//	if (mtx.try_lock())
	//	{
	//		// only increase if currently not locked
	//		++counter;
	//		mtx.unlock();
	//	}
	//}
}


int main()
{
	std::thread threads[10];
	for (int i = 0; i < 10; ++i)
		threads[i] = std::thread(attempt_10k_increases);

	for (std::thread& t : threads)
		t.join();
	std::cout << counter << " successful increases of the counter." << std::endl;

	getchar();
	return 0;
}
