
/***********************************************************
 * @name: std_time_mutex.cpp
 * @brief: time_mutex
 * @author: 梁基圣
 * @date: 2018/7/25 16:09:47
 * @version: 1.0
 **********************************************************/

// std::time_mutex比std::mutex多了两个成员函数，
// try_lock_for函数接受一个时间范围,表示在这一段时间范围之内
// 线程如果没有获得锁则被阻塞住(与std::mutex的try_lock()不同,
// try_lock如果被调用时没有获得锁则直接返回false),如果在此期
// 间其他线程释放了锁,则该线程可以获得对互斥量的锁,如果超时
// (即在指定时间内还是没有获得锁),则返回false.
// try_lock_until函数则接受一个时间点作为参数,在指定时间点未
// 到来之前线程如果没有获得锁则被阻塞住,如果在此期间其他线程
// 释放了锁,则该线程可以获得对互斥量的锁,如果超时(即在指定时
// 间内还是没有获得锁),则返回false.

#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

std::timed_mutex mtx;

void fireworks()
{
	// waiting to get a lock: each thread prints "-" every 200ms
	while (!mtx.try_lock_for(std::chrono::milliseconds(200)))
		std::cout << "-";

	// got a lock! - wait for ls, then this thread prints "*"
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "*";
	mtx.unlock();
}


int main()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i < 10; ++i)
		threads[i] = std::thread(fireworks);

	for (std::thread& t : threads)
		t.join();

	getchar();
	return 0;
}
