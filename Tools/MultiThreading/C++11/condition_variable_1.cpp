
/***********************************************************
 * @name: condition_variable_1.cpp
 * @brief: 条件变量
 * @author: 梁基圣
 * @date: 2018/7/22 15:25:04
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

using std::cout;
using std::endl;

void worker_thread()
{
	// Wait until main() sends data
	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk, [] { return ready; });

	// after the wait, we own the lock.
	cout << "Worker thread is processing data" << endl;
	data += " after processing";

	// Send data back to main()
	processed = true;
	cout << "Worker thread signals data processing completed" << endl;

	// Manual unlocking is done before notifying, to avoid waking up
	// the waiting thread only to block again (see notify_one for details)
	lk.unlock();
	cv.notify_one();
}


int main()
{
	std::thread worker(worker_thread);
	data = "Example data";

	// send data to the worker thread
	{
		std::lock_guard<std::mutex> lk(m);
		ready = true;
		cout << "main() signals data ready for processing" << endl;
	}
	cv.notify_one();

	// wait for the worker
	{
		std::unique_lock<std::mutex> lk(m);
		cv.wait(lk, [] { return processed; });
	}

	cout << "Back in main(), data = " << data << endl;

	return 0;
}
