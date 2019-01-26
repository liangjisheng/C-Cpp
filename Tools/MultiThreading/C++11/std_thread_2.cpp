
/***********************************************************
 * @name: std_thread_2.cpp
 * @brief: std::thread
 * @author: 梁基圣
 * @date: 2018/7/22 16:12:58
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <mutex>

std::mutex mu;

void f1(int n)
{
	for (int i = 0; i < 5; ++i)
	{
		mu.lock();
		std::cout << "Thread " << n << " executing" << std::endl;
		mu.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void f2(int& n)
{
	for (int i = 0; i < 5; ++i)
	{
		mu.lock();
		std::cout << "Thread 2 executing\n";
		mu.unlock();
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


int main()
{
	int n = 0; 
	std::thread t1;						// t1 is not a thread
	std::thread t2(f1, n + 1);			// pass by value
	std::thread t3(f2, std::ref(n));	// pass by reference
	std::thread t4(std::move(t3));		// t4 now is running f2(). t3 is no longer a thread

	t2.join();
	t4.join();

	std::cout << n << std::endl;

	return 0;
}
