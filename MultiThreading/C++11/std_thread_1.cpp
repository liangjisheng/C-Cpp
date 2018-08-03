
/***********************************************************
 * @name: std_thread_1.cpp
 * @brief: std::thread
 * @author: 梁基圣
 * @date: 2018/7/25 15:20:18
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

void thread_task(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "hello, world " << std::this_thread::get_id()
		<< " paused " << n << " seconds" << std::endl;
}


int main()
{
	std::thread threads[5];
	std::cout << "Spawning 5 threads..." << std::endl;
	for (int i = 0; i < 5; ++i)
		threads[i] = std::thread(thread_task, i + 1);

	std::cout << "Done spawning threads! Now wait for them to join." << std::endl;
	for (std::thread& t : threads)
		t.join();

	std::cout << "All threads joins" << std::endl;

	getchar();
	return 0;
}
