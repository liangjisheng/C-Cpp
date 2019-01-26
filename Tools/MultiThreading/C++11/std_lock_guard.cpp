
/***********************************************************
 * @name: std_lock_guard.cpp
 * @brief: lock_guard
 * @author: 梁基圣
 * @date: 2018/7/25 16:22:39
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>

std::mutex mtx;

void print_even(int x)
{
	if (0 == x % 2)
		std::cout << x << " is even\n";
	else
		throw (std::logic_error("not even"));
}

void print_thread_id(int id)
{
	try {
		// using a local lock_guard to lock mtx guarantees unlocking
		// on destruction / exception:
		// lck在构造函数里面将mtx上锁，析构时将mtx解锁
		std::lock_guard<std::mutex> lck(mtx);
		print_even(id);
	}
	catch (std::logic_error&)
	{
		std::cout << "[exception caught]" << std::endl;
	}
}


int main()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i < 10; ++i)
		threads[i] = std::thread(print_thread_id, i + 1);

	for (std::thread& t : threads)
		t.join();

	getchar();
	return 0;
}
