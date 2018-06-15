
#include <iostream>
#include <sstream>
#include <vector>
#include "Logger.h"


using std::cout;
using std::endl;
using std::vector;
using std::thread;
using std::stringstream;
using std::ref;


void logSomeMessages(int id, Logger& logger)
{
	for (int i = 0; i < 10; ++i)
	{
		stringstream ss;
		ss << "Log entry " << i << " from thread " << id;
		logger.log(ss.str());
	}
}


int main()
{
	Logger logger;
	vector<thread> threads;
	// 创建10个线程，每一个线程使用logSomeMessages(),共用一个Logger()类
	// Create a few threads all working with the same Logger instance.
	for (int i = 0; i < 10; ++i)
		threads.emplace_back(logSomeMessages, i, ref(logger));

	// Wait for all threads to finish.
	for (auto& t : threads)
		t.join();

	system("pause");
	return 0;
}

