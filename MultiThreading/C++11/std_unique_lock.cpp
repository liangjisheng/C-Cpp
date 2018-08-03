
/***********************************************************
 * @name: std_unique_lock.cpp
 * @brief: unique_lock
 * @author: 梁基圣
 * @date: 2018/7/25 16:31:31
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;		// mutex for critical section

void print_block(int n, char c)
{
	// critical section (exclusive access to std::cout signaled by 
	// lifetime of lck)
	// 与lock_guard相似，也是构造自动上锁，析构自动解锁，但提供了更好的
	// 上锁和解锁控制
	std::unique_lock<std::mutex> lck(mtx);
	for (int i = 0; i < n; ++i)
		std::cout << c;
	std::cout << std::endl;
}


int main()
{
	std::thread th1(print_block, 50, '*');
	std::thread th2(print_block, 50, '$');
	th1.join();
	th2.join();

	getchar();
	return 0;
}
