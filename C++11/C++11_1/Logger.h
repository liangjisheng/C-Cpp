#pragma once


// 演示了如何使用线程、互斥体、锁类和条件变量编写一个多线程的Logger类，这个类
// 允许不同的线程向一个队列中添加日志消息。Logger类本身会在另一个后台线程中处理
// 这个队列，将日志信息串行地写入一个文件，C++标准没有线程安全的队列，必须通过
// 一个互斥体保护队列的访问，避免多个线程同时读写队列。

#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <atomic>

//class Logger
//{
//public:
//	// Starts a background thread writing log entries to a file
//	Logger();
//	// Prevent copy construction and assignment.
//	Logger(const Logger& src) = delete;
//	Logger& operator=(const Logger& src) = delete;
//	// Add log entry to the queue
//	void log(const std::string& entry);
//
//private:
//	// The function running in the background thread.
//	void processEntries();
//	// Mutex and condition variable to protect access to the queue
//	std::mutex mMutex;
//	std::condition_variable mCondVar;
//	std::queue<std::string> mQueue;
//	// The backgournd thread
//	std::thread mThread;
//};


// 如果在多核计算机上构建并运行这个程序，会发现后台Logger线程会在main()函数
// 结束时突然中止。这意味着，任然在队列中的消息不会写入磁盘文件。当后台Logger
// 线程突然中止时，甚至一些运行时库会报错或生成一个崩溃转储。需要添加一个
// 机制来正常关闭后台线程，并在应用程序本身中止之前，等待后台线程完全关闭
// 这可以通过向类中添加一个析构函数和一个原子bool型成员变量解决


class Logger
{
public:
	// Starts a background thread writing log entries to a file
	Logger();
	virtual ~Logger();
	// Prevent copy construction and assignment.
	Logger(const Logger& src) = delete;
	Logger& operator=(const Logger& src) = delete;
	// Add log entry to the queue
	void log(const std::string& entry);

private:
	// The function running in the background thread.
	void processEntries();
	// Mutex and condition variable to protect access to the queue
	std::mutex mMutex;
	std::condition_variable mCondVar;
	std::queue<std::string> mQueue;
	// The backgournd thread
	std::thread mThread;
	// Boolean telling the background thread to terminate.
	std::atomic<bool> mExit;
};
